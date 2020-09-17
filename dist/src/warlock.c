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
 * Warlock Abilities v1.0 - December 2019                                   *
 ****************************************************************************/

#include <stdio.h>
#include <string.h>
#include "mud.h"

void show_warlock_abilities( CHAR_DATA *ch )
{
    ch_printf( ch, "\r\n             &C::: &wWarlock Abilities &C:::\r\n\r\n" );

    if( class_level( ch, CLASS_WARLOCK ) >= 2 && xIS_SET( ch->subclasses, SUBCLASS_FIEND ) )
        ch_printf( ch, "&wYou absorb temporary hit points from slain enemies equal to &c%d&z+&c%d&w.\r\n", cha_app[get_curr_cha( ch )].bonus, class_level( ch, CLASS_WARLOCK ) );

    return;
}