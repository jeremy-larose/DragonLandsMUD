/****************************************************************************
 * [S]imulated [M]edieval [A]dventure multi[U]ser [G]ame      |   \\._.//   *
 * -----------------------------------------------------------|   (0...0)   *
 * SMAUG 1.8 (C) 1994, 1995, 1996, 1998  by Derek Snider      |    ).:.(    *
 * -----------------------------------------------------------|    {o o}    *
 * SMAUG code team: Thoric, Altrag, Blodkai, Narn, Haus,      |   / ' ' \   *
 * Scryn, Rennard, Swordbearer, Gorog, Grishnakh, Nivek,      |~'~.VxvxV.~'~*
 * Tricops, Fireblade, Edmond, Conran                         |             *
 * ------------------------------------------------------------------------ *
 * Merc 2.1 Diku Mud improvments copyright (C) 1992, 1993 by Michael        *
 * Chastain, Michael Quan, and Mitchell Tse.                                *
 * Original Diku Mud copyright (C) 1990, 1991 by Sebastian Hammer,          *
 * Michael Seifert, Hans Henrik St{rfeldt, Tom Madsen, and Katja Nyboe.     *
 * ------------------------------------------------------------------------ *
 *                          Dragonlands of Chaos MUD                        *
 *                           by Seikyr and Beltane                          *
 * ------------------------------------------------------------------------ *
 * Rogue Abilities v1.0 - November 2018                                     *
 ****************************************************************************/

#include <stdio.h>
#include <string.h>
#include "mud.h"

void show_rogue_abilities( CHAR_DATA *ch )
{
    char buf[MAX_STRING_LENGTH];

    ch_printf( ch, "\r\n             &C::: &wRogue Abilities &C:::\r\n\r\n" );

    if( class_level( ch, CLASS_ROGUE ) >= 10 )
        ch_printf( ch, "&wYou %s &wlearned how to uncanny dodge, using your reaction to halve the damage against you.\r\n",
            ch->pcdata->learned[gsn_uncanny_dodge] > 0 ? "&Ghave" : "&zhave not" );
               
    if( class_level( ch, CLASS_ROGUE ) >= 14 )
        ch_printf( ch, "&wYou %s &wlearned how to evade area effects, letting you take no damage instead of half damage on successful Dexterity checks.\r\n",
            ch->pcdata->learned[gsn_evasion] > 0 ? "&Ghave" : "&zhave not" );
                  
    if( class_level( ch, CLASS_ROGUE ) >= 28 )
        ch_printf( ch, "&wYou %s &wlearned how to hone your senses, letting you see any invisible or hidden creature within 10 feet as long as you can hear.\r\n",
            ch->pcdata->learned[gsn_blindsense] > 0 ? "&Ghave" : "&zhave not" );         
               
    if( class_level( ch, CLASS_ROGUE )  >= 38 )
        snprintf( buf, MAX_STRING_LENGTH, "%s", "10d6" );
    else if( class_level( ch, CLASS_ROGUE ) >= 34 )
        snprintf( buf, MAX_STRING_LENGTH, "%s", "9d6" );
    else if( class_level( ch, CLASS_ROGUE ) >= 30 )
        snprintf( buf, MAX_STRING_LENGTH, "%s", "8d6" );
    else if( class_level( ch, CLASS_ROGUE ) >= 26 )
        snprintf( buf, MAX_STRING_LENGTH, "%s", "7d6" );
    else if( class_level( ch, CLASS_ROGUE ) >= 22 )
        snprintf( buf, MAX_STRING_LENGTH, "%s", "6d6" );
    else if( class_level( ch, CLASS_ROGUE ) >= 18  )
        snprintf( buf, MAX_STRING_LENGTH, "%s", "5d6" );
    else if( class_level( ch, CLASS_ROGUE ) >= 14 )
        snprintf( buf, MAX_STRING_LENGTH, "%s", "4d6" );
    else if( class_level( ch, CLASS_ROGUE ) >= 10 )
        snprintf( buf, MAX_STRING_LENGTH, "%s", "3d6" );
    else if( class_level( ch, CLASS_ROGUE ) >= 6 )
        snprintf( buf, MAX_STRING_LENGTH, "%s", "2d6" );
    else
        snprintf( buf, MAX_STRING_LENGTH, "%s", "1d6" );
   
        ch_printf( ch, "&wYou make sneak attacks on foes that are engaged in combat or can't see you at a &G+%s &wdamage bonus.\r\n", buf );
    return;
}

void do_stroke_of_luck( CHAR_DATA *ch, const char *argument )
{
    COOLDOWN_DATA *cooldown;
    int diceroll;
    bool skill_found = FALSE;
    
    if( !has_class( ch, CLASS_ROGUE ) )
    {
        send_to_char( "That ability is for rogues only!\r\n", ch );
        return;
    }
    
    for( cooldown = ch->first_cooldown; cooldown; cooldown = cooldown->next )
    {
        if( cooldown->sn == gsn_stroke_of_luck )
        {
            if( cooldown->curr_available >= 1 )
            {
                while( ( diceroll = number_bits( 5 ) ) >= 10 )
                ;
                ch_printf( ch, "&GYou feel your lucky stars align and your next miss will automatically hit!\r\n" );
                xSET_BIT( ch->affected_by, AFF_LUCKY );
                --cooldown->curr_available;
                skill_found = TRUE;
                cooldown->wait = skill_table[gsn_stroke_of_luck]->cooldown;
                break;
            }
            else
            {
                send_to_char( "You can't channel your stroke of luck anymore today.\r\n", ch );
                return;
            }
            return;
        }
    }
    if( skill_found != TRUE )
    {
        ch_printf( ch, "&GYou feel your lucky stars align and your next miss will automatically hit!\r\n" );
        xSET_BIT( ch->affected_by, AFF_LUCKY );
        CREATE( cooldown, COOLDOWN_DATA, 1 );
            cooldown->sn = gsn_stroke_of_luck;
            cooldown->curr_available = 0;
            cooldown->max_available = 1;
            cooldown->wait = skill_table[gsn_stroke_of_luck]->cooldown;
        LINK( cooldown, ch->first_cooldown, ch->last_cooldown, next, prev );
        return;
    }
}
