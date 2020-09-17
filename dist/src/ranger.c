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
 * Ranger skills v1.0 - February 2020                                       *
 ****************************************************************************/

#include <stdio.h>
#include <string.h>
#include "mud.h"

void show_ranger_abilities( CHAR_DATA * ch )
{
        ch_printf( ch, "\r\n             &C::: &wRanger Abilities &C:::\r\n\r\n" );
        if( xIS_SET( ch->abilities, ABIL_FAVORED_HUMAN ) )
            send_to_char( "&wYou will do additional damage to &GHumans &wwhen you engage them in combat.\r\n", ch );
        if( xIS_SET( ch->abilities, ABIL_LANDS_STRIDE ) )
            send_to_char( "&wYou suffer no movement penalty when moving through difficult terrain.\r\n", ch );
        if( xIS_SET( ch->abilities, ABIL_FERAL_SENSES ) )
            send_to_char( "&wYou have feral senses, allowing you to sense enemies you cannot see.\r\n", ch );

        if( xIS_SET( ch->abilities, ABIL_COLOSSUS_SLAYER ) )
            send_to_char( "&wYou are a colossus slayer, allowing you to deal an extra 1d8 damage per turn.\r\n", ch );
        if( xIS_SET( ch->abilities, ABIL_GIANT_KILLER ) )
            send_to_char( "&wYou are a giant killer, allowing you to counterattack whenever you are missed in combat.\r\n", ch );
        if( xIS_SET( ch->abilities, ABIL_HORDE_BREAKER ) )
            send_to_char( "&wYou are a horde breaker, allowing you to hit two opponents per round with an attack.\r\n", ch );
        return;
}