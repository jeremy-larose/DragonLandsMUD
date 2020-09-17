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
 * Fighter skills v1.0 - July 2018                                          *
 ****************************************************************************/

#include <stdio.h>
#include <string.h>
#include "mud.h"

short roll_superiority( CHAR_DATA * ch )
{
    short roll = 0;

    if( class_level( ch, CLASS_FIGHTER ) <= 19 )
        roll = dice( 1, 8 );
    else if( class_level( ch, CLASS_FIGHTER ) <= 35 )
        roll = dice( 1, 10 );
    else if( class_level( ch, CLASS_FIGHTER ) >= 36 )
        roll = dice( 1, 12 );
    //ch_printf( ch, "You feel superior! +%d damage.\r\n", roll );
    return roll;
}

void show_fighter_abilities( CHAR_DATA * ch )
{   
    OBJ_DATA *obj;

    ch_printf( ch, "\r\n             &C::: &wFighter Abilities &C:::\r\n\r\n" );
    if( ch->pcdata->learned[gsn_archery_style] > 0 )
        ch_printf( ch, "&wYou gain +2 to your ranged weapon attack rolls.\r\n" );
    if( ch->pcdata->learned[gsn_defense_style] > 0 )
        ch_printf( ch, "&wYou gain a +1 bonus to your AC while wearing armor.\r\n" );
    if( ch->pcdata->learned[gsn_dueling_style] > 0 )
        ch_printf( ch, "&wYou gain a +2 to damage rolls when using one single weapon.\r\n" );
    if( ch->pcdata->learned[gsn_great_weapon_style] > 0 )
        ch_printf( ch, "&wYou can reroll damage dice if you roll a 1 or 2 when using a two-handed or versatile weapon.\r\n" );
    if( ch->pcdata->learned[gsn_protection_style] > 0 )
        ch_printf( ch, "&wYou can use your reaction to impose a disadvantage when using a shield.\r\n" );         
    if( ch->pcdata->learned[gsn_two_weapon_style] > 0 )
        ch_printf( ch, "&wYou can add your ability modifier to the damage of your offhand attack.\r\n" );

    if( class_level( ch, CLASS_FIGHTER ) >= 6 )
       ch_printf( ch, "&wYou %s &wlearned how to score a critical hit on a 19 or 20 hit roll.\r\n", ch->pcdata->learned[gsn_improved_critical] > 0 ? "&Ghave" : "&zhave not" );
    if( class_level( ch, CLASS_FIGHTER ) >= 10 )
       ch_printf( ch, "&wYou %s &wlearned how to make a second attack in battle.\r\n", ch->pcdata->learned[gsn_second_attack] > 0 ? "&Ghave" : "&zhave not" );
    if( class_level( ch, CLASS_FIGHTER ) >= 14 )
       ch_printf( ch, "&wYou %s &wlearned how to add your +%d modifier to a Strength, Constitution, or Dexterity check.\r\n", ch->pcdata->learned[gsn_remarkable_athlete] > 0 ? "&Ghave" : "&zhave not", level_prog_table[ch->level].bonus );
    if( class_level( ch, CLASS_FIGHTER ) >= 22 )
       ch_printf( ch, "&wYou %s &wlearned how to make a third attack in battle.\r\n", ch->pcdata->learned[gsn_third_attack] > 0 ? "&Ghave" : "&zhave not" );
    if( class_level( ch, CLASS_FIGHTER ) >= 30 )
       ch_printf( ch, "&wYou %s &wlearned how to score a critical hit on a 18-20 roll.\r\n", ch->pcdata->learned[gsn_superior_critical] > 0 ? "&Ghave" : "&zhave not" );
    if( class_level( ch, CLASS_FIGHTER ) >= 36 )
    {
       ch_printf( ch, "&wYou %s &wlearned how to reroll a saving throw that you fail.\r\n", ch->pcdata->learned[gsn_indomitable] > 0 ? "&Ghave" : "&zhave not" );
       ch_printf( ch, "&wYou regenerate %d hit points when you have less than half your hp remaining per turn in combat.\r\n", 5+con_app[get_curr_con( ch )].bonus );
    }
    if( class_level( ch, CLASS_FIGHTER ) >= 40 )
       ch_printf( ch, "&wYou %s &wlearned how to make a fourth attack in battle.\r\n", ch->pcdata->learned[gsn_fourth_attack] > 0 ? "&Ghave" : "&zhave not" );

    if( xIS_SET( ch->subclasses, SUBCLASS_CHAMPION ) )
    {
       ch_printf( ch, "&wYou %s &wlearned how to score a critical hit on a 19 or 20 hit roll.\r\n", ch->pcdata->learned[gsn_improved_critical] > 0 ? "&Ghave" : "&zhave not" );
       ch_printf( ch, "&wYou %s &wlearned how to score a critical hit on a 18-20 roll.\r\n", ch->pcdata->learned[gsn_superior_critical] > 0 ? "&Ghave" : "&zhave not" );
    if( ch->pcdata->learned[gsn_survivor] > 0 )
       ch_printf( ch, "&wYou regenerate %d hit points when you have less than half your hp remaining per turn in combat.\r\n", 5+con_app[get_curr_con( ch )].bonus );
    }

    if( xIS_SET( ch->subclasses, SUBCLASS_BATTLEMASTER ) )
    {
        short diceroll = 0;
        if( class_level( ch, CLASS_FIGHTER ) < 19 ) diceroll = 8;
        else if( class_level( ch, CLASS_FIGHTER ) >= 20 && class_level( ch, CLASS_FIGHTER ) <= 35) diceroll = 10;
        else if( class_level( ch, CLASS_FIGHTER ) >= 36 ) diceroll = 12;
        ch_printf( ch, "&wYou have &G%d &wof &G%d &w1d%d combat superiority dice remaining.\r\n", ch->classvalues[0], ch->classvalues[1], diceroll );
    }

    if( xIS_SET( ch->subclasses, SUBCLASS_ELD_KNIGHT ) )
    {
        send_to_char( "&wYou are currently bonded to the following weapons: \r\n", ch );
        if( ch->bondedweapon[0] == 0 )
           send_to_char( "&wNone.\r\n", ch );
        else
        {
            obj = get_bonded_obj_world( ch, ch->bondedweapon[0] );
            if( obj )
                ch_printf( ch, "Bonded Weapon found! Vnum %d: %s\r\n", obj->pIndexData->vnum, obj->short_descr );
            else
                ch_printf( ch, "Error! Null bonded weapon.\r\n" );
        }
    }
}

void do_maneuvers( CHAR_DATA *ch, const char *argument )
{
    int dice = 0;
    char arg[MAX_INPUT_LENGTH];
    argument = one_argument( argument, arg );

    if( !xIS_SET( ch->subclasses, SUBCLASS_BATTLEMASTER ) )
    {
        send_to_char( "You don't know any combat maneuvers.\r\n", ch );
        return;
    }

    if( arg[0] == '\0' )
    {   
        if( class_level( ch, CLASS_FIGHTER ) <= 13 )
            dice = 4;
        else if( class_level( ch, CLASS_FIGHTER ) <= 29 )
            dice = 5;
        else
            dice = 6;
        if( class_level( ch, CLASS_FIGHTER ) >= 6 )
            ch_printf( ch, "&cYou have &w%d &ccombat superiority dice.\r\n", dice );

        ch_printf( ch, "&cYou &w%s &ctry to &Udisarm&d &copponents with every blow.\r\n", xIS_SET( ch->abilities, ABIL_DISARMING_STRIKE ) ? "&Gdo" : "&zdo not" );
        ch_printf( ch, "&cYou &w%s &ctry to &Udistract&d &copponents with every blow.\r\n", xIS_SET( ch->abilities, ABIL_DISTRACTING_STRIKE ) ? "&Gdo" : "&zdo not" );
        ch_printf( ch, "&cYou &w%s &ctry to &Udisarm &d&copponents with every blow.\r\n", xIS_SET( ch->abilities, ABIL_DISARMING_STRIKE ) ? "&Gdo" : "&zdo not" );
        ch_printf( ch, "&cYou &w%s &ctry to &Ugoad &d&copponents with every blow.\r\n", xIS_SET( ch->abilities, ABIL_GOADING_ATTACK ) ? "&Gdo" : "&zdo not" );
        ch_printf( ch, "&cYou &w%s &ctry to &Ufeint &d&copponents with every blow.\r\n", xIS_SET( ch->abilities, ABIL_FEINT ) ? "&Gdo" : "&zdo not" );
        ch_printf( ch, "&cYou &w%s &ctry to &Uparry &d&copponents with every blow.\r\n", xIS_SET( ch->abilities, ABIL_PARRY ) ? "&Gdo" : "&zdo not" );

        return;
    }

    if( !str_cmp( arg, "disarm" ) )
    {
        if( !xIS_SET( ch->abilities, ABIL_DISARMING_STRIKE ) )
        {
            ch_printf( ch, "&cYou will now attempt to &Udisarm&d &cyour opponent with every blow.\r\n" );
            xTOGGLE_BIT( ch->abilities, ABIL_DISARMING_STRIKE );
        }
        else
        {
            ch_printf( ch, "&cYou will no longer attempt to &Udisarm&d &cyour opponent with every blow.\r\n" );
            xTOGGLE_BIT( ch->abilities, ABIL_DISARMING_STRIKE );
        }
        return;
    }

    if( !str_cmp( arg, "distract" ) )
    {
        if( !xIS_SET( ch->abilities, ABIL_DISTRACTING_STRIKE ) )
        {
            ch_printf( ch, "&cYou will now attempt to &Udistract&d &cyour opponent with every blow.\r\n" );
            xTOGGLE_BIT( ch->abilities, ABIL_DISTRACTING_STRIKE );
        }
        else
        {
            ch_printf( ch, "&cYou will no longer attempt to &Udistract&d &cyour opponent with every blow.\r\n" );
            xTOGGLE_BIT( ch->abilities, ABIL_DISTRACTING_STRIKE );
        }
        return;
    }

}

void do_second_wind( CHAR_DATA *ch, const char *argument )
{
    COOLDOWN_DATA *cooldown;
    int diceroll;
    bool skill_found = FALSE;
    
    if( !has_class( ch, CLASS_FIGHTER ) )
    {
        send_to_char( "That ability is for fighters only!\r\n", ch );
        return;
    }
    
    for( cooldown = ch->first_cooldown; cooldown; cooldown = cooldown->next )
    {
        if( cooldown->sn == gsn_second_wind )
        {
            if( cooldown->curr_available >= 1 )
            {
                while( ( diceroll = number_bits( 5 ) ) >= 10 )
                ;
                ch_printf( ch, "&GYou draw strength from deep within your spirit, channeling your second wind! [&w+%d&Whp&G]\r\n", diceroll+(ch->level/2) );
                ch->hit += diceroll+( ch->level/2 );
                if( ch->hit > ch->max_hit )
                    ch->hit = ch->max_hit; 
                --cooldown->curr_available;
                skill_found = TRUE;
                cooldown->wait = skill_table[gsn_second_wind]->cooldown;
                break;
            }
            else
            {
                send_to_char( "You can't channel your second wind anymore today.\r\n", ch );
                return;
            }
            return;
        }
    }
    if( skill_found != TRUE )
    {
        while( ( diceroll = number_bits( 5 ) ) >= 10 )
        ;
        ch_printf( ch, "&GYou draw strength from deep within your spirit, channeling your second wind! [&w+%d&Whp&G]\r\n", diceroll+(ch->level/2) );
        ch->hit += diceroll+( ch->level/2 );
        if( ch->hit > ch->max_hit )
            ch->hit = ch->max_hit;
        
        CREATE( cooldown, COOLDOWN_DATA, 1 );
            cooldown->sn = gsn_second_wind;
            cooldown->curr_available = 0;
            cooldown->max_available = 1;
            cooldown->wait = skill_table[gsn_second_wind]->cooldown;
        LINK( cooldown, ch->first_cooldown, ch->last_cooldown, next, prev );
        return;
    }
}

void do_action_surge( CHAR_DATA *ch, const char *argument )
{
    COOLDOWN_DATA *cooldown;
    bool skill_found = FALSE;
    if( !has_class( ch, CLASS_FIGHTER ) )
    {
        send_to_char( "You can't do that!\r\n", ch );
        return;
    }
    
    if( ch->bonus_action == TRUE )
    {
        send_to_char( "You're already surging with power!\r\n", ch );
        return;
    }
    for( cooldown = ch->first_cooldown; cooldown; cooldown = cooldown->next )
    {
        if( cooldown->sn == gsn_action_surge )
        {
            if( cooldown->curr_available >= 1 )
            {
                ch_printf( ch, "&RYou feel a surge of energy course through your veins, empowering you!\r\n" );
                ch->bonus_action = TRUE;
                --cooldown->curr_available;
                skill_found = TRUE;
                cooldown->wait = skill_table[gsn_action_surge]->cooldown;
                break;
            }
            else
            {
                send_to_char( "You can't action surge anymore today.\r\n", ch );
                return;
            }
            return;
        }
    }
    if( skill_found != TRUE )
    {
        ch_printf( ch, "&RYou feel a surge of energy course through your veins, empowering you!\r\n" );
        ch->bonus_action = TRUE;
        
        CREATE( cooldown, COOLDOWN_DATA, 1 );
            cooldown->sn = gsn_action_surge;
            cooldown->curr_available = 0;
            if( class_level( ch, CLASS_FIGHTER ) <= 33 )
                cooldown->max_available = 1;
            else
                cooldown->max_available = 2;
            cooldown->wait = skill_table[gsn_action_surge]->cooldown;
        LINK( cooldown, ch->first_cooldown, ch->last_cooldown, next, prev );
        return;
    }
}

void do_indomitable( CHAR_DATA *ch, const char *argument )
{
    COOLDOWN_DATA *cooldown;
    bool skill_found = FALSE;

    if( !has_class( ch, CLASS_FIGHTER ) )
    {
        send_to_char( "You can't do that!\r\n", ch );
        return;
    }
    
    if( xIS_SET( ch->abilities, ABIL_INDOMITABLE ) )
    {
        send_to_char( "You're already indomitable!\r\n", ch );
        return;
    }

    for( cooldown = ch->first_cooldown; cooldown; cooldown = cooldown->next )
    {
        if( cooldown->sn == gsn_indomitable )
        {
            if( cooldown->curr_available >= 1 )
            {
                ch_printf( ch, "&RYou feel a surge of energy course through your veins, empowering you!\r\n" );
                xTOGGLE_BIT( ch->abilities, ABIL_INDOMITABLE );
                --cooldown->curr_available;
                skill_found = TRUE;
                cooldown->wait = skill_table[gsn_indomitable]->cooldown;
                break;
            }
            else
            {
                send_to_char( "You can't become indomitable anymore today.\r\n", ch );
                return;
            }
            return;
        }
    }
    if( skill_found != TRUE )
    {
        ch_printf( ch, "&RYou feel a surge of energy course through your veins, empowering you!\r\n" );
        xTOGGLE_BIT( ch->abilities, ABIL_INDOMITABLE );
        
        CREATE( cooldown, COOLDOWN_DATA, 1 );
            cooldown->sn = gsn_indomitable;
            cooldown->curr_available = 0;
            if( class_level( ch, CLASS_FIGHTER ) >= 34 )
                cooldown->max_available = 3;
            else if( class_level( ch, CLASS_FIGHTER ) <= 26 )
                cooldown->max_available = 2;
            else if( class_level( ch, CLASS_FIGHTER ) <= 18 )
                cooldown->max_available = 1;
            cooldown->wait = skill_table[gsn_indomitable]->cooldown;
        LINK( cooldown, ch->first_cooldown, ch->last_cooldown, next, prev );
        return;
    }
}

void do_study( CHAR_DATA *ch, const char * argument )
{
    char arg[MAX_INPUT_LENGTH];
    CHAR_DATA *victim;

    argument = one_argument( argument, arg );

    if( arg[0] == '\0' )
    {
        send_to_char( "Study whom?\r\n", ch );
        return;
    }

    if( ( victim = get_char_room( ch, arg ) ) == NULL )
    {
        send_to_char( "They aren't here.\r\n", ch );
        return;
    }

    if( victim == ch )
    {
        send_to_char( "You intently study yourself, but learn nothing interesting.\r\n", ch );
        return;
    }

    ch_printf( ch, "You study %s's movements, mannerisms, and abilities, and learn the following:\r\n", PERS( victim, ch, FALSE ) );
    ch_printf( ch, "They have a Strength score of %d.\r\n", get_curr_str( victim ) );
    ch_printf( ch, "They have a Dexterity score of %d.\r\n", get_curr_dex( victim ) );
    ch_printf( ch, "They have a Constitution score of %d.\r\n", get_curr_con( victim ) );
    ch_printf( ch, "Their current Armor Class is %d.\r\n", GET_AC( victim ) );
    ch_printf( ch, "They look to have %d Hit Points remaining.\r\n", victim->hit );
    ch_printf( ch, "They are Level %d, and have %d Fighter levels.\r\n", victim->level, class_level( victim, CLASS_FIGHTER ) );
    return;
}

void do_pushing_attack( CHAR_DATA *ch, const char * argument )
{
    char arg[MAX_INPUT_LENGTH];
    char arg2[MAX_INPUT_LENGTH];
    int exit_dir;
    EXIT_DATA *pexit;
    CHAR_DATA *victim;
    bool nogo;
    ROOM_INDEX_DATA *to_room;
    int schance = 0;
    short temp;

    argument = one_argument( argument, arg );
    argument = one_argument( argument, arg2 );

    if( get_timer( ch, TIMER_PKILLED ) > 0 )
    {
        send_to_char( "You can't shove a player right now.\r\n", ch );
        return;
    }

    if( arg[0] == '\0' )
    {
        send_to_char( "Shove whom?\r\n", ch );
        return;
    }

    if( ( victim = get_char_room( ch, arg ) ) == NULL )
    {
        send_to_char( "They aren't here.\r\n", ch );
        return;
    }
    
    if( victim == ch )
    {
        send_to_char( "You shove yourself around, to no avail.\r\n", ch );
        return;
    }

    if( !IS_NPC( victim ) && !IS_SET( victim->pcdata->flags, PCFLAG_DEADLY ) )
    {
        send_to_char( "You can only shove deadly characters.\r\n", ch );
        return;
    }

    if( ch->classvalues[0] <= 0 )
    {
        send_to_char( "You try to perform a pushing attack, but you lack the energy required to muster the strength.\r\n", ch );
        return;
    }

    if( xIS_SET( ch->abilities, ABIL_PUSHING_ATTACK ) ) 
    {
        send_to_char( "You're already prepared to devastate your opponent with your next blow!\r\n", ch );
        return;
    }

    if( get_timer( victim, TIMER_PKILLED ) > 0 )
    {
        send_to_char( "You can't shove that player right now.\r\n", ch );
        return;
    }

    if( ( victim->position ) < POS_FIGHTING )
    {
        act( AT_PLAIN, "$N isn't standing up.", ch, NULL, victim, TO_CHAR );
        return;
    }

    if( arg2[0] == '\0' )
    {
        send_to_char( "Shove them in which direction?\r\n", ch );
        return;
    }

    exit_dir = get_dir( arg2 );
    if( xIS_SET( victim->in_room->room_flags, ROOM_SAFE ) && get_timer( victim, TIMER_SHOVEDRAG ) <= 0 )
    {
        send_to_char( "That character cannot be shoved right now.\r\n", ch );
        return;
    }

    nogo = FALSE;
    if( ( pexit = get_exit( ch->in_room, exit_dir ) ) == NULL )
        nogo = TRUE;
    else
        if( IS_SET( pexit->exit_info, EX_CLOSED )
            && ( !IS_AFFECTED( victim, AFF_PASS_DOOR ) || IS_SET( pexit->exit_info, EX_NOPASSDOOR ) ) )
        nogo = TRUE;

    if( nogo )
    {
        send_to_char( "There's no exit in that direction.\r\n", ch );
        return;
    }

    to_room = pexit->to_room;
    if( xIS_SET( to_room->room_flags, ROOM_DEATH ) )
    {
        send_to_char( "You cannot shove someone into a death trap.\r\n", ch );
        return;
    }

    if( ch->in_room->area != to_room->area && !in_hard_range( victim, to_room->area ) )
    {
        send_to_char( "That character cannot enter that area.\r\n", ch );
        return;
    }

    if( victim->size > SIZE_LARGE )
    {
        send_to_char( "They're far too big to push around.\r\n", ch );
        return;
    }

    if( dc_strength( victim ) > dc_maneuver( ch ) )
    {
        act( AT_WHITE, "$n attempts to crash into you and push you back, but you hold your ground!", ch, NULL, victim, TO_VICT );
        act( AT_WHITE, "$n attempts to crash into $N and push them back, but $E holds $S ground!", ch, NULL, victim, TO_NOTVICT );
        act( AT_WHITE, "You attempt to charge and slam into $N to push $M back, but $E holds $S ground!", ch, NULL, victim, TO_CHAR );
        return;
    }
    else
    {
        xTOGGLE_BIT( ch->abilities, ABIL_PUSHING_ATTACK );
        act( AT_WHITE, "$n takes a running charge and crashes into you, sending you flying!", ch, NULL, victim, TO_VICT );
        act( AT_WHITE, "$n takes a running step and crashes into $N, sending $M flying!", ch, NULL, victim, TO_NOTVICT );
        act( AT_WHITE, "You take a running step and crash into $N with your shoulder, sending $M flying!", ch, NULL, victim, TO_CHAR );
        one_hit( ch, victim, TYPE_UNDEFINED );
        temp = victim->position;
        victim->position = POS_SHOVE;

        move_char( victim, get_exit( ch->in_room, exit_dir ), 0, exit_dir );
        if( !char_died( victim ) )
            victim->position = temp;
    }

    ch->classvalues[0]--;
    return;
}

void do_eldritch_strike( CHAR_DATA * ch, const char *argument )
{
    if( !has_class( ch, SUBCLASS_ELD_KNIGHT ) )
    {
        send_to_char( "You are not an eldritch knight!\r\n", ch );
        return;
    }

    if( xIS_SET( ch->abilities, ABIL_ELDRITCH_STRIKE ) ) 
    {
        send_to_char( "You're already prepared to eldritch strike your opponent with your next blow!\r\n", ch );
        return;
    }

    send_to_char( "You prepare to make your next attack an eldritch strike!\r\n", ch );
    xTOGGLE_BIT( ch->abilities, ABIL_ELDRITCH_STRIKE );
    return;
}

void do_menacing_attack( CHAR_DATA * ch, const char *argument )
{
    if( ch->classvalues[0] <= 0 )
    {
        send_to_char( "You try to perform a devastating blow, but you lack the energy required to perform the maneuver.\r\n", ch );
        return;
    }

    if( xIS_SET( ch->abilities, ABIL_MENACING_ATTACK ) ) 
    {
        send_to_char( "You're already prepared to devastate your opponent with your next blow!\r\n", ch );
        return;
    }

    send_to_char( "You prepare to make your next attack a menacing blow!\r\n", ch );
    ch->classvalues[0]--;
    xTOGGLE_BIT( ch->abilities, ABIL_MENACING_ATTACK );
    return;
}

void do_evasive_attack( CHAR_DATA * ch, const char *argument )
{
    if( ch->classvalues[0] <= 0 )
    {
        send_to_char( "You try to perform evasive attacks, but you lack the energy required to perform the maneuver.\r\n", ch );
        return;
    }

    if( xIS_SET( ch->abilities, ABIL_EVASIVE_ATTACK ) ) 
    {
        send_to_char( "You're already prepared to evade your opponent with your next movement!\r\n", ch );
        return;
    }

    send_to_char( "You prepare to evade your opponent's blows!\r\n", ch );
    ch->classvalues[0]--;
    xTOGGLE_BIT( ch->abilities, ABIL_EVASIVE_ATTACK );
    return;
}

void do_riposte( CHAR_DATA * ch, const char *argument )
{
    if( ch->classvalues[0] <= 0 )
    {
        send_to_char( "You try to perform a riposte, but you lack the energy required to perform the maneuver.\r\n", ch );
        return;
    }

    if( xIS_SET( ch->abilities, ABIL_RIPOSTE ) ) 
    {
        send_to_char( "You're already prepared to riposte your opponent with their next attack!\r\n", ch );
        return;
    }

    send_to_char( "You prepare to intercept your opponent's next attack with a riposte!\r\n", ch );
    ch->classvalues[0]--;
    xTOGGLE_BIT( ch->abilities, ABIL_RIPOSTE );
    return;
}

void do_goading_attack( CHAR_DATA * ch, const char *argument )
{
    if( ch->classvalues[0] <= 0 )
    {
        send_to_char( "You try to taunt, but you lack the energy required to perform the maneuver.\r\n", ch );
        return;
    }

    if( xIS_SET( ch->abilities, ABIL_GOADING_ATTACK ) ) 
    {
        send_to_char( "You're already prepared to taunt your opponent with your next blow!\r\n", ch );
        return;
    }

    send_to_char( "You prepare to make your next attack a taunting blow!\r\n", ch );
    ch->classvalues[0]--;
    xTOGGLE_BIT( ch->abilities, ABIL_GOADING_ATTACK );
    return;
}

void do_trip_attack( CHAR_DATA * ch, const char *argument )
{
    if( ch->classvalues[0] <= 0 )
    {
        send_to_char( "You try to trip, but you lack the energy required to perform the maneuver.\r\n", ch );
        return;
    }

    if( xIS_SET( ch->abilities, ABIL_TRIP_ATTACK ) ) 
    {
        send_to_char( "You're already prepared to trip your opponent with your next blow!\r\n", ch );
        return;
    }

    send_to_char( "You prepare to make your next attack a tripping blow!\r\n", ch );
    ch->classvalues[0]--;
    xTOGGLE_BIT( ch->abilities, ABIL_TRIP_ATTACK );
    return;
}

void do_feint( CHAR_DATA * ch, const char *argument )
{
    if( ch->classvalues[0] <= 0 )
    {
        send_to_char( "You try to feint, but you lack the energy required to perform the maneuver.\r\n", ch );
        return;
    }

    if( xIS_SET( ch->abilities, ABIL_FEINT ) ) 
    {
        send_to_char( "You're already prepared to feint the next strike!\r\n", ch );
        return;
    }

    send_to_char( "You prepare to make your next attack merely a feint!\r\n", ch );
    ch->advantage = TRUE;
    ch->classvalues[0]--;
    xTOGGLE_BIT( ch->abilities, ABIL_FEINT );
    return;
}

void do_commanders_strike( CHAR_DATA *ch, const char *argument )
{
    char arg[MAX_STRING_LENGTH];
    CHAR_DATA *victim;
    argument = one_argument( argument, arg );

    if( arg[0] == '\0' )
    {
        send_to_char( "Commandeer whom to attack?\r\n", ch );
        return;
    } 

    if( ( victim = get_char_world( ch, arg ) ) == NULL )
    {
        send_to_char( "They aren't here.\r\n", ch );
        return;
    } 

    if( ch->classvalues[0] <= 0 )
    {
        send_to_char( "You try to command, but you lack the energy required to perform the maneuver.\r\n", ch );
        return;
    }

    if( xIS_SET( victim->abilities, ABIL_COMMANDERS_STRIKE ) ) 
    {
        send_to_char( "They're already prepared to commandeer the next strike!\r\n", ch );
        return;
    }

    send_to_char( "You inspire them to deliver a commanding blow!\r\n", ch );
    act( AT_WHITE, "$n inspires you to fight bravely, allowing you to attack once more!", ch, NULL, victim, TO_VICT );
    ch->classvalues[0]--;
    xTOGGLE_BIT( victim->abilities, ABIL_COMMANDERS_STRIKE );
    return;
}

void do_maneuvering_attack( CHAR_DATA *ch, const char *argument )
{
    char arg[MAX_STRING_LENGTH];
    CHAR_DATA *victim;
    argument = one_argument( argument, arg );
    char buf[MAX_INPUT_LENGTH];

    if( arg[0] == '\0' )
    {
        send_to_char( "Command whom to maneuver?\r\n", ch );
        return;
    } 

    if( ( victim = get_char_world( ch, arg ) ) == NULL )
    {
        send_to_char( "They aren't here.\r\n", ch );
        return;
    } 

    if( ch->classvalues[0] <= 0 )
    {
        send_to_char( "You try to command them, but you lack the energy required to perform the maneuver.\r\n", ch );
        return;
    }

    if( xIS_SET( victim->affected_by, AFF_DISENGAGE ) ) 
    {
        send_to_char( "They're already prepared to maneuver!\r\n", ch );
        return;
    }
    mudstrlcpy( buf, "I will hold the line, make a break for it!", 512 );
    colorize_speech( buf, ch );
    act( AT_WHITE, "You yell to $N that the coast is clear and you'll hold the line!\r\n", ch, NULL, victim, TO_CHAR );
    act( AT_WHITE, "$n yells to you, \"$t&w\"", ch, buf, victim, TO_VICT );
    ch->classvalues[0]--;
    xTOGGLE_BIT( victim->affected_by, AFF_DISENGAGE );
    return;
}

void do_parry( CHAR_DATA * ch, const char *argument )
{
    if( ch->classvalues[0] <= 0 )
    {
        send_to_char( "You try to parry, but you lack the energy required to perform the maneuver.\r\n", ch );
        return;
    }

    if( xIS_SET( ch->abilities, ABIL_PARRY ) ) 
    {
        send_to_char( "You're already prepared to parry the next strike!\r\n", ch );
        return;
    }

    send_to_char( "You prepare to parry the next attack that comes your way!\r\n", ch );
    ch->classvalues[0]--;
    xTOGGLE_BIT( ch->abilities, ABIL_PARRY );
    return;
}

void do_distracting_strike( CHAR_DATA * ch, const char *argument )
{
    if( ch->classvalues[0] <= 0 )
    {
        send_to_char( "You try to perform a distracting strike, but you lack the energy required to perform the maneuver.\r\n", ch );
        return;
    }

    if( xIS_SET( ch->abilities, ABIL_DISTRACTING_STRIKE ) ) 
    {
        send_to_char( "You're already prepared to distract with the next strike!\r\n", ch );
        return;
    }

    send_to_char( "You prepare to make your next attack a distraction!\r\n", ch );
    ch->advantage = TRUE;
    ch->classvalues[0]--;
    xTOGGLE_BIT( ch->abilities, ABIL_DISTRACTING_STRIKE );
    return;
}

void do_arcane_charge( CHAR_DATA *ch, const char *argument )
{
    char arg[MAX_INPUT_LENGTH];
    bool skill_found = FALSE;
    COOLDOWN_DATA *cooldown;

    argument = one_argument( argument, arg );

    if( !xIS_SET( ch->subclasses, SUBCLASS_ELD_KNIGHT ) )
    {
        send_to_char( "You are not an eldritch knight!\r\n", ch );
        return;
    }

    if( class_level( ch, CLASS_FIGHTER ) <= 30 )
    {
        send_to_char( "You must be at least level 30 as an Eldritch Knight to arcane charge.\r\n", ch );
        return;
    }

    if( arg[0] == '\0' )
    {
        send_to_char( "Arcane charge in which direction?\r\n", ch );
        return;
    }
    for( cooldown = ch->first_cooldown; cooldown; cooldown = cooldown->next )
    {
        if( cooldown->sn == gsn_action_surge )
        {
            if( cooldown->curr_available >= 1 )
            {
                --cooldown->curr_available;
                skill_found = TRUE;
                cooldown->wait = skill_table[gsn_action_surge]->cooldown;
                break;
            }
            else
            {
                send_to_char( "You can't teleport anymore today.\r\n", ch );
                return;
            }
            return;
        }
    }
    if( skill_found != TRUE )
    {
        ch_printf( ch, "&RYou feel a surge of energy course through your veins, empowering you!\r\n" );
        ch->bonus_action = TRUE;
        
        CREATE( cooldown, COOLDOWN_DATA, 1 );
            cooldown->sn = gsn_action_surge;
            cooldown->curr_available = 0;
            if( class_level( ch, CLASS_FIGHTER ) <= 33 )
                cooldown->max_available = 1;
            else
                cooldown->max_available = 2;
            cooldown->wait = skill_table[gsn_action_surge]->cooldown;
        LINK( cooldown, ch->first_cooldown, ch->last_cooldown, next, prev );
    }
    xSET_BIT( ch->abilities, ABIL_ARCANE_CHARGE );    
    if( !str_cmp( arg, "north" ) || !str_cmp( arg, "n" ) )
    {
        act( AT_MAGIC, "$n winks out of existence.", ch, NULL, NULL, TO_ROOM );
        move_char( ch, get_exit(ch->in_room, DIR_NORTH), 0, DIR_NORTH );
    }

    if( !str_cmp( arg, "south" ) || !str_cmp( arg, "s" )  )
    {
        act( AT_MAGIC, "$n winks out of existence.", ch, NULL, NULL, TO_ROOM );
        move_char( ch, get_exit(ch->in_room, DIR_SOUTH ), 0, DIR_SOUTH );
    }

    if( !str_cmp( arg, "east" ) || !str_cmp( arg, "e" ) )
    {
        act( AT_MAGIC, "$n winks out of existence.", ch, NULL, NULL, TO_ROOM );
        move_char( ch, get_exit(ch->in_room, DIR_EAST ), 0, DIR_EAST );
    }

    if( !str_cmp( arg, "west" ) || !str_cmp( arg, "w" ) )
    {
        act( AT_MAGIC, "$n winks out of existence.", ch, NULL, NULL, TO_ROOM );
        move_char( ch, get_exit(ch->in_room, DIR_WEST ), 0, DIR_WEST );
    }
    
    xREMOVE_BIT( ch->abilities, ABIL_ARCANE_CHARGE );
    act( AT_MAGIC, "A swirling portal appears and $n walks out.", ch, NULL, NULL, TO_ROOM );
    return;
}

void do_bond( CHAR_DATA * ch, const char *argument )
{
    OBJ_DATA *obj;
    char arg[MAX_INPUT_LENGTH];
    char buf[MAX_STRING_LENGTH];

    argument = one_argument( argument, arg );

    if( !xIS_SET( ch->subclasses, SUBCLASS_ELD_KNIGHT ) )
    {
        send_to_char( "You are not an eldritch knight!\r\n", ch );
        return;
    }

    if( class_level( ch, CLASS_FIGHTER ) <= 6 )
    {
        send_to_char( "You must be at least 6th level to create a bond with your weapon.\r\n", ch );
        return;
    }

    if( arg[0] == '\0' )
    {   
        send_to_char( "Usage: bond <weapon> or bond summon <weapon>.\r\n", ch );
        return;
    }

    if( !str_cmp( arg, "summon" ) )
    {
        if( ( obj = get_bonded_obj_world( ch, ch->bondedweapon[0] ) ) == NULL )
        {
            send_to_char( "You can't seem to locate it.\r\n", ch );
            return;
        }

        if( obj )
        {
            OBJ_DATA *weapon;
            if( obj->carried_by )
            {
                act( AT_WHITE, "$p winks out of existence.", obj->carried_by, obj, NULL, TO_ROOM );
                separate_obj( obj );
                obj_from_char( obj );
            }
            else
            {
                separate_obj( obj );
                obj_from_room( obj );
            }

            if( CAN_WEAR( obj, ITEM_TAKE ) )
                obj = obj_to_char( obj, ch );
            else
                obj = obj_to_room( obj, ch->in_room, ch );


            /*
            if( ( obj = get_eq_char( victim, WEAR_WIELD ) ) == NULL && ( obj = get_eq_char( victim, WEAR_MAIN_HAND ) ) == NULL )
            {
                //log_printf( "Victim: %s not wielding a weapon, attempting disarm.", victim->name );
            }

           if( ( tmpobj = get_eq_char( victim, WEAR_DUAL_WIELD ) ) != NULL && number_bits( 1 ) == 0 )
                obj = tmpobj; */

            if( ( weapon = get_eq_char( ch, WEAR_WIELD ) ) == NULL && ( weapon = get_eq_char( ch, WEAR_MAIN_HAND ) ) == NULL )
            {
  //              log_printf( "Bond: %s not wielding a weapon or using a main_hand item. Equipping %s.", ch->name, obj->name );
                act( AT_MAGIC, "$n closes $s eyes briefly and $p magically fades existence into $s open hand.", ch, obj, NULL, TO_ROOM );
                act( AT_MAGIC, "Through sheer force of will, you summon $p into your free hand.", ch, obj, NULL, TO_CHAR );
                equip_char( ch, obj, WEAR_MAIN_HAND );
                return;
            }

            if( ( weapon = get_eq_char( ch, WEAR_WIELD ) ) != NULL || ( weapon = get_eq_char( ch, WEAR_MAIN_HAND ) ) != NULL )
            {
//                log_printf( "Bond: %s is already wielding %s; unequipping.", ch->name, weapon->name );
                act( AT_MAGIC, "$n closes $s eyes briefly and $p magically fades existence into $s open hand.", ch, obj, NULL, TO_ROOM );
                act( AT_MAGIC, "Through sheer force of will, you summon $p into your free hand, tossing aside your old weapon.", ch, obj, NULL, TO_CHAR );
                unequip_char( ch, weapon );
//                log_printf( "Bond: %s unequipped. Equipping new weapon: %s", weapon->name, obj->name );
                equip_char( ch, obj, WEAR_MAIN_HAND );
                return;
            }
            return;
        }
    }
    else
    {
        if( ( obj = get_obj_here( ch, arg ) ) == NULL )
        {
            send_to_char( "You can't seem to find that weapon.\r\n", ch );
            return;
        }

        if( obj )
        {
            act( AT_WHITE, "$n kneels and touches $p to his forehead, uttering an eldritch incantation...", ch, obj, NULL, TO_ROOM );
            ch_printf( ch, "You are now bonded to %s!\r\n", obj->short_descr );
            separate_obj( obj );
            if( str_infix( "bonded", obj->name ) )
            {
                snprintf( buf, MAX_STRING_LENGTH, "%s %s %s", obj->name, "bonded", ch->name );
                STRFREE( obj->name );
                obj->name = STRALLOC( buf );
            }
            ch->bondedweapon[0] = obj->pIndexData->vnum;
            return;
        }
    }
}