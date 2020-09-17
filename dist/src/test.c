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
 * Function Test File -  May 2020                                           *
 ****************************************************************************/

#include <stdio.h>
#include <string.h>
#include "mud.h"

void do_weapontest( CHAR_DATA *ch, const char *argument )
{
    OBJ_DATA *obj;

    obj = get_wielded_obj( ch, false );

    if( obj )
        ch_printf( ch, "Currently Wielding: %s\r\n", obj->short_descr );
    else
        ch_printf( ch, "Not currently wielding anything.\r\n" );
    return;
}




