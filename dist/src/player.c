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
 *             Commands for personal player settings/statictics             *
 ****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "mud.h"

/*
 *  Locals
 */
const char *tiny_affect_loc_name( int location );

void do_gold( CHAR_DATA* ch, const char* argument)
{

   ch_printf( ch, "&WYou have &Y%s gold&W, ", num_punct( ch->gold ) );
   ch_printf( ch, "&w%s silver", num_punct( ch->silver ) );
   ch_printf( ch,"&W, and &O%s copper &Wcoins.\n\r", num_punct( ch->copper ) );
   return;
}
/* This function you can play with variables to get to learn how things work. Printing variables is great practice
 * for you to learn to code.
 * Seikyr 7.05.2018
 */
void do_printtest( CHAR_DATA *ch, const char * argument )
{  
   ch_printf( ch, "I want to learn about: My sector! = %d", ch->in_room->sector_type );
   return;
}

void do_worth( CHAR_DATA* ch, const char* argument )
{
   char buf[MAX_STRING_LENGTH];
   char buf2[MAX_STRING_LENGTH];

   if( IS_NPC( ch ) )
      return;

   set_pager_color( AT_SCORE, ch );
   pager_printf( ch, "\r\nWorth for %s%s.\r\n", ch->name, ch->pcdata->title );
   send_to_pager( " ----------------------------------------------------------------------------\r\n", ch );
   if( !ch->pcdata->deity )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "N/A" );
   else if( ch->pcdata->favor > 2250 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "loved" );
   else if( ch->pcdata->favor > 2000 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "cherished" );
   else if( ch->pcdata->favor > 1750 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "honored" );
   else if( ch->pcdata->favor > 1500 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "praised" );
   else if( ch->pcdata->favor > 1250 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "favored" );
   else if( ch->pcdata->favor > 1000 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "respected" );
   else if( ch->pcdata->favor > 750 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "liked" );
   else if( ch->pcdata->favor > 250 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "tolerated" );
   else if( ch->pcdata->favor > -250 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "ignored" );
   else if( ch->pcdata->favor > -750 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "shunned" );
   else if( ch->pcdata->favor > -1000 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "disliked" );
   else if( ch->pcdata->favor > -1250 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "dishonored" );
   else if( ch->pcdata->favor > -1500 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "disowned" );
   else if( ch->pcdata->favor > -1750 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "abandoned" );
   else if( ch->pcdata->favor > -2000 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "despised" );
   else if( ch->pcdata->favor > -2250 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "hated" );
   else
      snprintf( buf, MAX_STRING_LENGTH, "%s", "damned" );

   if( ch->level < 10 )
   {
      if( ch->alignment > 900 )
         snprintf( buf2, MAX_STRING_LENGTH, "%s", "devout" );
      else if( ch->alignment > 700 )
         snprintf( buf2, MAX_STRING_LENGTH, "%s", "noble" );
      else if( ch->alignment > 350 )
         snprintf( buf2, MAX_STRING_LENGTH, "%s", "honorable" );
      else if( ch->alignment > 100 )
         snprintf( buf2, MAX_STRING_LENGTH, "%s", "worthy" );
      else if( ch->alignment > -100 )
         snprintf( buf2, MAX_STRING_LENGTH, "%s", "neutral" );
      else if( ch->alignment > -350 )
         snprintf( buf2, MAX_STRING_LENGTH, "%s", "base" );
      else if( ch->alignment > -700 )
         snprintf( buf2, MAX_STRING_LENGTH, "%s", "evil" );
      else if( ch->alignment > -900 )
         snprintf( buf2, MAX_STRING_LENGTH, "%s", "ignoble" );
      else
         snprintf( buf2, MAX_STRING_LENGTH, "%s", "fiendish" );
   }
   else
      snprintf( buf2, MAX_STRING_LENGTH, "%d", ch->alignment );
   pager_printf( ch, "|Level: %-4d |Favor: %-10s |Alignment: %-9s |Experience: %-9d|\r\n", ch->level, buf, buf2, ch->exp );
   send_to_pager( " ----------------------------------------------------------------------------\r\n", ch );
   switch ( ch->style )
   {
      case STYLE_EVASIVE:
         snprintf( buf, MAX_STRING_LENGTH, "%s", "evasive" );
         break;
      case STYLE_DEFENSIVE:
         snprintf( buf, MAX_STRING_LENGTH, "%s", "defensive" );
         break;
      case STYLE_AGGRESSIVE:
         snprintf( buf, MAX_STRING_LENGTH, "%s", "aggressive" );
         break;
      case STYLE_BERSERK:
         snprintf( buf, MAX_STRING_LENGTH, "%s", "berserk" );
         break;
      default:
         snprintf( buf, MAX_STRING_LENGTH, "%s", "standard" );
         break;
   }
   pager_printf( ch, "|Glory: %-4d |Weight: %-9d |Style: %-13s |Gold: %-14s |\r\n",
                 ch->pcdata->quest_curr, ch->carry_weight, buf, num_punct( ch->gold ) );
   pager_printf(ch, "|            |Silver: %-9s",
                 num_punct(ch->silver));
   pager_printf(ch, " |Copper: %-13s|                     |\n\r",
                  num_punct(ch->copper));
   send_to_pager( " ----------------------------------------------------------------------------\r\n", ch );
   if( ch->level < 15 && !IS_PKILL( ch ) )
      pager_printf( ch, "|            |Hitroll: -------- |Damroll: ----------- |                     |\r\n" );
   else
      pager_printf( ch, "|            |Hitroll: %-8d |Damroll: %-11d |                     |\r\n", GET_HITROLL( ch ),
                    GET_DAMROLL( ch ) );
   send_to_pager( " ----------------------------------------------------------------------------\r\n", ch );
   return;
}

/*
 * New score command by Haus
 */
void do_score( CHAR_DATA* ch, const char* argument )
{
   char buf[MAX_STRING_LENGTH];
   AFFECT_DATA *paf;
   int iLang;
   int mod;
   OBJ_DATA *wield;
   /*const char *suf;
   short day;

   day = ch->pcdata->day + 1;

   if( day > 4 && day < 20 )
      suf = "th";
   else if( day % 10 == 1 )
      suf = "st";
   else if( day % 10 == 2 )
      suf = "nd";
   else if( day % 10 == 3 )
      suf = "rd";
   else
      suf = "th";
   * - Uncomment this if you want Birthdays dispayed on score for players - Kayle 1/22/08
   */

   if( ch->alignment > 800 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "Lawful Good" );
   else if( ch->alignment > 600 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "Neutral Good" );
   else if( ch->alignment > 400 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "Chaotic Good" );
   else if( ch->alignment > 200 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "Lawful Neutral" );
   else if( ch->alignment < 200 && ch->alignment > -200 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "True Neutral" );
   else if( ch->alignment < -200 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "Chaotic Neutral" );
   else if( ch->alignment < -400 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "Lawful Evil" );
   else if( ch->alignment < -600 )
      snprintf( buf, MAX_STRING_LENGTH, "%s", "Neutral Evil" );
   else if( ch->alignment < -800)
      snprintf( buf, MAX_STRING_LENGTH, "%s", "Chaotic Evil" );
      
   if( class_table[ch->Class]->spell_mod_stat == 1 )
      mod = str_app[get_curr_str( ch )].bonus;
   else if( class_table[ch->Class]->spell_mod_stat == 2 )
      mod = dex_app[get_curr_dex( ch )].bonus;
   else if( class_table[ch->Class]->spell_mod_stat == 3 )
      mod = int_app[get_curr_int( ch )].bonus;
   else if( class_table[ch->Class]->spell_mod_stat == 4 )
      mod = wis_app[get_curr_wis( ch )].bonus;
   else if( class_table[ch->Class]->spell_mod_stat == 5 )
      mod = con_app[get_curr_con( ch )].bonus;
   else 
      mod = cha_app[get_curr_cha( ch )].bonus;


   pager_printf( ch, "\r\n&Y|&W%15s                              &WLv&C%-3d &W%s %10.10s %11.11s  &Y|",
                  ch->name, ch->level, ( !xIS_SET( ch->subrace, SUBRACE_PURE ) ? capitalize( ext_flag_string( &ch->subrace, subrace_flags ) ) : "" ), get_race( ch ), get_class( ch ) );
   pager_printf( ch, "\r\n&Y|  &W%-45s &cSubclasses: &C%-15s &Y|", IS_NPC(ch) ? "" : ch->adjective, capitalize( ext_flag_string( &ch->subclasses, subclass_flags ) ) );
   pager_printf( ch, "\r\n&Y|  &WBackground: &c%s", capitalize( background_types[ch->pcdata->background] ) );
   pager_printf( ch, "\r\n&Y|---------------------------------------------------------------------------&Y|&W " );
   
   pager_printf( ch, "\r\n&Y| &cProficiency :        &W+&C%2.2d  &Y| &cArmor Class    : &C%2d &w(&C%2d Base&w)                 &Y|&W ",
                level_prog_table[ch->level].bonus, GET_AC( ch ), ch->base_armor );
   pager_printf( ch, "\r\n&Y| &cStrength    :    &C%2.2d &c(%s+%2d&c) &Y| &cHit Points     : &C%3.3d&c/&C%3.3d                      &Y| &W",
                get_curr_str( ch ), ( class_table[ch->Class]->saving_throw_one == 1 || class_table[ch->Class]->saving_throw_two == 1 ) ? "&P" : "&W",
                str_app[get_curr_str( ch )].bonus,
                ch->hit, ch->max_hit );
   pager_printf( ch, "\r\n&Y| &cDexterity   :    &C%2.2d &c(%s+%2d&c) &Y| &cSize           : &C%-12s                 &Y| &W",
                get_curr_dex( ch ), ( class_table[ch->Class]->saving_throw_one == 2 || class_table[ch->Class]->saving_throw_two == 2 ) ? "&P" : "&W",
                dex_app[get_curr_dex( ch )].bonus,
                 capitalize( size_table[ch->size] ) );
   pager_printf( ch, "\r\n&Y| &cConstitution:    &C%2.2d &c(%s+%2d&c) &Y| &cCasting Ability: &C%-12s                 &Y|&W ",
                get_curr_con( ch ), ( class_table[ch->Class]->saving_throw_one == 5 || class_table[ch->Class]->saving_throw_two == 5 ) ? "&P" : "&W",
                con_app[get_curr_con( ch )].bonus,
                 capitalize( affect_loc_name( class_table[ch->Class]->spell_mod_stat ) ) );
   pager_printf( ch, "\r\n&Y| &cWisdom      :    &C%2.2d &c(%s+%2d&c) &Y| &cSpell Save DC  : &C%-2d                           &Y|&W ",
                get_curr_wis( ch ), ( class_table[ch->Class]->saving_throw_one == 4 || class_table[ch->Class]->saving_throw_two == 4 ) ? "&P" : "&W",
                wis_app[get_curr_wis( ch )].bonus,
                 (mod+(8 + level_prog_table[ch->level].bonus )) );
   pager_printf( ch, "\r\n&Y| &cIntelligence:    &C%2.2d &c(%s+%2d&c) &Y| &cBackground     : &CUnavailable                  &Y|&W ",
                get_curr_int( ch ), ( class_table[ch->Class]->saving_throw_one == 3 || class_table[ch->Class]->saving_throw_two == 3 ) ? "&P" : "&W",
                int_app[get_curr_int( ch )].bonus );
   pager_printf( ch, "\r\n&Y| &cCharisma    :    &C%2.2d &c(%s+%2d&c) &Y| &cDivine Domain  : &CUnavailable                  &Y|&W ",
                get_curr_cha( ch ), ( class_table[ch->Class]->saving_throw_one == 25 || class_table[ch->Class]->saving_throw_two == 25 ) ? "&P" : "&W",
                cha_app[get_curr_cha( ch )].bonus );
   pager_printf( ch, "\r\n&Y| &cLuck        :    &C%2.2d &c(&W+%2d&c) &Y| &cAlignment      : &C%-15s              &Y|&W ",
                get_curr_lck( ch ), lck_app[get_curr_lck( ch )].bonus, buf );
   pager_printf( ch, "\r\n&Y|---------------------------------------------------------------------------&Y|" );
   pager_printf( ch, "\r\n&Y| &RCombat Statistics &Y                                                        |&W " );
   

   pager_printf( ch, "\r\n&Y| &cSpell Attack Bonus: &C%12.12s                            &W+&C%2.2d           &Y|",
                capitalize( affect_loc_name( class_table[ch->Class]->spell_mod_stat ) ), (mod+level_prog_table[ch->level].bonus) );
/*   
   if( ( wield = get_eq_char( ch, WEAR_OFF_HAND ) ) != NULL )
   {
      if( dual_flip == FALSE )
      {
         dual_flip = TRUE;
         wield = get_eq_char( ch, WEAR_MAIN_HAND );
      }
      else
         dual_flip = FALSE;
   }
   else if( ( wield = get_eq_char( ch, WEAR_TWOHAND ) ) != NULL && wield->item_type == ITEM_WEAPON )
      wield = get_eq_char( ch, WEAR_TWOHAND );
   else
      wield = get_eq_char( ch, WEAR_MAIN_HAND );
 */     

   if ( ( wield = get_eq_char( ch, WEAR_TWOHAND ) ) != NULL )
      pager_printf( ch, "\r\n&Y| &cBoth Hands        : &C%-30.30s&c  &cTo Hit: &W+&C%-2d  &C%2d&Wd&C%-2d&W+&C%2d &Y|",
                   wield->short_descr, weapon_prof_bonus_check( ch, wield, &wield->value[4] ), wield->value[1], wield->value[2],  GET_DAMROLL( ch ) );
   else if( ( wield = get_eq_char( ch, WEAR_MAIN_HAND ) ) != NULL )
      pager_printf( ch, "\r\n&Y| &cMain Hand         : &C%-30.30s&c  &cTo Hit: &W+&C%-2d  &C%2d&Wd&C%-2d&W+&C%2d &Y|",
                wield->short_descr, weapon_prof_bonus_check( ch, wield, &wield->value[4]), wield->value[1], wield->value[2], GET_DAMROLL(ch) );
   else
      pager_printf( ch, "\r\n&Y| &cWeapon            : &CBarehanded                       &cTo Hit: &W+&C%-2d &C%2d&Wd&C%-2d&W+&C%2d &Y|",
                weapon_prof_bonus_check( ch, wield, &gsn_pugilism ), ch->barenumdie, ch->baresizedie, ch->damplus );
      
   if ( ( wield = get_eq_char( ch, WEAR_OFF_HAND ) ) != NULL && wield->item_type == ITEM_WEAPON )
   {
      pager_printf( ch, "\r\n&Y| &cOff Hand          : &C%-30.30s&c  &cTo Hit: &W+&C%-2d  &C%2d&Wd&C%-2d&W+&C%2d &Y|",
                wield->short_descr, weapon_prof_bonus_check( ch, wield, &wield->value[4] ), wield->value[1], wield->value[2],  GET_DAMROLL(ch) );
   }
   
   pager_printf( ch, "\r\n&Y| &cAttacks Per Round :                                          &C%2d           &Y|",
                ch->numattacks );
   pager_printf( ch, "\r\n&Y| &cInitiative        :                                          &C%2d           &Y|",
                dex_app[get_curr_dex( ch )].bonus );
   pager_printf( ch, "\r\n&Y|---------------------------------------------------------------------------&Y|\r\n" );

   if( !IS_NPC( ch ) && ch->pcdata->condition[COND_DRUNK] > 10 )
      send_to_pager( "You are drunk.\r\n", ch );
   if( !IS_NPC( ch ) && ch->pcdata->condition[COND_THIRST] == 0 )
      send_to_pager( "You are in danger of dehydrating.\r\n", ch );
   if( !IS_NPC( ch ) && ch->pcdata->condition[COND_FULL] == 0 )
      send_to_pager( "You are starving to death.\r\n", ch );
   if( ch->position != POS_SLEEPING )
      switch ( ch->mental_state / 10 )
      {
         default:
            send_to_pager( "You're completely messed up!\r\n", ch );
            break;
         case -10:
            send_to_pager( "You're barely conscious.\r\n", ch );
            break;
         case -9:
            send_to_pager( "You can barely keep your eyes open.\r\n", ch );
            break;
         case -8:
            send_to_pager( "You're extremely drowsy.\r\n", ch );
            break;
         case -7:
            send_to_pager( "You feel very unmotivated.\r\n", ch );
            break;
         case -6:
            send_to_pager( "You feel sedated.\r\n", ch );
            break;
         case -5:
            send_to_pager( "You feel sleepy.\r\n", ch );
            break;
         case -4:
            send_to_pager( "You feel tired.\r\n", ch );
            break;
         case -3:
            send_to_pager( "You could use a rest.\r\n", ch );
            break;
         case -2:
            send_to_pager( "You feel a little under the weather.\r\n", ch );
            break;
         case -1:
            send_to_pager( "You feel fine.\r\n", ch );
            break;
         case 0:
            send_to_pager( "You feel great.\r\n", ch );
            break;
         case 1:
            send_to_pager( "You feel energetic.\r\n", ch );
            break;
         case 2:
            send_to_pager( "Your mind is racing.\r\n", ch );
            break;
         case 3:
            send_to_pager( "You can't think straight.\r\n", ch );
            break;
         case 4:
            send_to_pager( "Your mind is going 100 miles an hour.\r\n", ch );
            break;
         case 5:
            send_to_pager( "You're high as a kite.\r\n", ch );
            break;
         case 6:
            send_to_pager( "Your mind and body are slipping apart.\r\n", ch );
            break;
         case 7:
            send_to_pager( "Reality is slipping away.\r\n", ch );
            break;
         case 8:
            send_to_pager( "You have no idea what is real, and what is not.\r\n", ch );
            break;
         case 9:
            send_to_pager( "You feel immortal.\r\n", ch );
            break;
         case 10:
            send_to_pager( "You are a Supreme Entity.\r\n", ch );
            break;
      }
   else if( ch->mental_state > 45 )
      send_to_pager( "Your sleep is filled with strange and vivid dreams.\r\n", ch );
   else if( ch->mental_state > 25 )
      send_to_pager( "Your sleep is uneasy.\r\n", ch );
   else if( ch->mental_state < -35 )
      send_to_pager( "You are deep in a much needed sleep.\r\n", ch );
   else if( ch->mental_state < -25 )
      send_to_pager( "You are in deep slumber.\r\n", ch );
/*   send_to_pager( "Languages: ", ch );
   for( iLang = 0; lang_array[iLang] != LANG_UNKNOWN; iLang++ )
      if( knows_language( ch, lang_array[iLang], ch ) || ( IS_NPC( ch ) && ch->speaks == 0 ) )
      {
         if( lang_array[iLang] & ch->speaking || ( IS_NPC( ch ) && !ch->speaking ) )
            set_pager_color( AT_RED, ch );
         send_to_pager( lang_names[iLang], ch );
         send_to_pager( " ", ch );
         set_pager_color( AT_SCORE, ch );
      }
   send_to_pager( "\r\n", ch );

   if( ch->pcdata->bestowments && ch->pcdata->bestowments[0] != '\0' )
      pager_printf( ch, "You are bestowed with the command(s): %s.\r\n", ch->pcdata->bestowments );

   if( ch->morph && ch->morph->morph )
   {
      send_to_pager( "----------------------------------------------------------------------------\r\n", ch );
      if( IS_IMMORTAL( ch ) )
         pager_printf( ch, "Morphed as (%d) %s with a timer of %d.\r\n",
                       ch->morph->morph->vnum, ch->morph->morph->short_desc, ch->morph->timer );
      else
         pager_printf( ch, "You are morphed into a %s.\r\n", ch->morph->morph->short_desc );
      send_to_pager( "----------------------------------------------------------------------------\r\n", ch );
   }
   if( CAN_PKILL( ch ) )
   {
      send_to_pager( "----------------------------------------------------------------------------\r\n", ch );
      pager_printf( ch, "PKILL DATA:  Pkills (%3.3d)     Illegal Pkills (%3.3d)     Pdeaths (%3.3d)\r\n",
                    ch->pcdata->pkills, ch->pcdata->illegal_pk, ch->pcdata->pdeaths );
   }
   if( ch->pcdata->clan && ch->pcdata->clan->clan_type != CLAN_ORDER && ch->pcdata->clan->clan_type != CLAN_GUILD )
   {
      send_to_pager( "----------------------------------------------------------------------------\r\n", ch );
      pager_printf( ch, "CLAN STATS:  %-14.14s  Clan AvPkills : %-5d  Clan NonAvpkills : %-5d\r\n",
                    ch->pcdata->clan->name, ch->pcdata->clan->pkills[6],
                    ( ch->pcdata->clan->pkills[1] + ch->pcdata->clan->pkills[2] +
                      ch->pcdata->clan->pkills[3] + ch->pcdata->clan->pkills[4] + ch->pcdata->clan->pkills[5] ) );
      pager_printf( ch, "                             Clan AvPdeaths: %-5d  Clan NonAvpdeaths: %-5d\r\n",
                    ch->pcdata->clan->pdeaths[6],
                    ( ch->pcdata->clan->pdeaths[1] + ch->pcdata->clan->pdeaths[2] +
                      ch->pcdata->clan->pdeaths[3] + ch->pcdata->clan->pdeaths[4] + ch->pcdata->clan->pdeaths[5] ) );
   }
   if( ch->pcdata->deity )
   {
      send_to_pager( "----------------------------------------------------------------------------\r\n", ch );
      if( ch->pcdata->favor > 2250 )
         snprintf( buf, MAX_STRING_LENGTH, "%s", "loved" );
      else if( ch->pcdata->favor > 2000 )
         snprintf( buf, MAX_STRING_LENGTH, "%s", "cherished" );
      else if( ch->pcdata->favor > 1750 )
         snprintf( buf, MAX_STRING_LENGTH, "%s", "honored" );
      else if( ch->pcdata->favor > 1500 )
         snprintf( buf, MAX_STRING_LENGTH, "%s", "praised" );
      else if( ch->pcdata->favor > 1250 )
         snprintf( buf, MAX_STRING_LENGTH, "%s", "favored" );
      else if( ch->pcdata->favor > 1000 )
         snprintf( buf, MAX_STRING_LENGTH, "%s", "respected" );
      else if( ch->pcdata->favor > 750 )
         snprintf( buf, MAX_STRING_LENGTH, "%s", "liked" );
      else if( ch->pcdata->favor > 250 )
         snprintf( buf, MAX_STRING_LENGTH, "%s", "tolerated" );
      else if( ch->pcdata->favor > -250 )
         snprintf( buf, MAX_STRING_LENGTH, "%s", "ignored" );
      else if( ch->pcdata->favor > -750 )
         snprintf( buf, MAX_STRING_LENGTH, "%s", "shunned" );
      else if( ch->pcdata->favor > -1000 )
         snprintf( buf, MAX_STRING_LENGTH, "%s", "disliked" );
      else if( ch->pcdata->favor > -1250 )
         snprintf( buf, MAX_STRING_LENGTH, "%s", "dishonored" );
      else if( ch->pcdata->favor > -1500 )
         snprintf( buf, MAX_STRING_LENGTH, "%s", "disowned" );
      else if( ch->pcdata->favor > -1750 )
         snprintf( buf, MAX_STRING_LENGTH, "%s", "abandoned" );
      else if( ch->pcdata->favor > -2000 )
         snprintf( buf, MAX_STRING_LENGTH, "%s", "despised" );
      else if( ch->pcdata->favor > -2250 )
         snprintf( buf, MAX_STRING_LENGTH, "%s", "hated" );
      else
         snprintf( buf, MAX_STRING_LENGTH, "%s", "damned" );
      pager_printf( ch, "Deity:  %-20s  Favor: %s\r\n", ch->pcdata->deity->name, buf );
   }
   if( ch->pcdata->clan && ch->pcdata->clan->clan_type == CLAN_ORDER )
   {
      send_to_pager( "----------------------------------------------------------------------------\r\n", ch );
      pager_printf( ch, "Order:  %-20s  Order Mkills:  %-6d   Order MDeaths:  %-6d\r\n",
                    ch->pcdata->clan->name, ch->pcdata->clan->mkills, ch->pcdata->clan->mdeaths );
   }
   if( ch->pcdata->clan && ch->pcdata->clan->clan_type == CLAN_GUILD )
   {
      send_to_pager( "----------------------------------------------------------------------------\r\n", ch );
      pager_printf( ch, "Guild:  %-20s  Guild Mkills:  %-6d   Guild MDeaths:  %-6d\r\n",
                    ch->pcdata->clan->name, ch->pcdata->clan->mkills, ch->pcdata->clan->mdeaths );
   }
   if( IS_IMMORTAL( ch ) )
   {
      send_to_pager( "----------------------------------------------------------------------------\r\n", ch );

      pager_printf( ch, "IMMORTAL DATA:  Wizinvis [%s]  Wizlevel (%d)\r\n",
                    xIS_SET( ch->act, PLR_WIZINVIS ) ? "X" : " ", ch->pcdata->wizinvis );

      pager_printf( ch, "Bamfin:  %s %s\r\n", ch->name, ( ch->pcdata->bamfin[0] != '\0' )
                    ? ch->pcdata->bamfin : "appears in a swirling mist." );
      pager_printf( ch, "Bamfout: %s %s\r\n", ch->name, ( ch->pcdata->bamfout[0] != '\0' )
                    ? ch->pcdata->bamfout : "leaves in a swirling mist." );
    
   } */
   if( ch->first_affect )
   {
      int i;
      SKILLTYPE *sktmp;

      i = 0;
      send_to_pager( "&Y|---------------------------------------------------------------------------|\r\n", ch );
      send_to_pager( "&Y| &WYou are affected by:                                                      &Y|\r\n", ch );
      for( paf = ch->first_affect; paf; paf = paf->next )
      {
         if( ( sktmp = get_skilltype( paf->type ) ) == NULL )
            continue;
         if( ch->level < 20 )
         {
            pager_printf( ch, "&Y| &W%-34.34s&Y]    ", sktmp->name );
            if( i == 0 )
               i = 2;
            if( ( ++i % 3 ) == 0 )
               send_to_pager( "&Y|\r\n", ch );
         }
         if( ch->level >= 20 )
         {
            if( paf->modifier == 0 )
               pager_printf( ch, "&C[&c%-24.24s &Wfor &c%5d &Wrds&C]    ", sktmp->name, paf->duration );
            else if( paf->modifier > 999 )
               pager_printf( ch, "&C[&c%-15.15s&W; &c%7.7s &Wfor &c%5d &Wrds&C]    ",
                             sktmp->name, tiny_affect_loc_name( paf->location ), paf->duration );
            else
               pager_printf( ch, "&C[&c%-11.11s&W; &c%+-3.3d %7.7s&W for &c%5d &Wrds&C]    ",
                             sktmp->name, paf->modifier, tiny_affect_loc_name( paf->location ), paf->duration );
            if( i == 0 )
               i = 1;
            if( ( ++i % 2 ) == 0 )
               send_to_pager( "&Y|\r\n", ch );
         }
      }
   }
   if( ch->pcdata->area )
   {
      pager_printf( ch, "Vnums:   Room (%-5.5d - %-5.5d)   Object (%-5.5d - %-5.5d)   Mob (%-5.5d - %-5.5d)\r\n",
                  ch->pcdata->area->low_r_vnum, ch->pcdata->area->hi_r_vnum,
                  ch->pcdata->area->low_o_vnum, ch->pcdata->area->hi_o_vnum,
                  ch->pcdata->area->low_m_vnum, ch->pcdata->area->hi_m_vnum );
      pager_printf( ch, "Area Loaded [%s]\r\n", ( IS_SET( ch->pcdata->area->status, AREA_LOADED ) ) ? "yes" : "no" );
   }
   send_to_pager( "\r\n", ch );
      /*
       * Area Loaded info - Scryn 8/11
       */
   return;
}

/*
 * Return ascii name of an affect location.
 */
const char *tiny_affect_loc_name( int location )
{
   switch ( location )
   {
      case APPLY_NONE:
         return "NIL";
      case APPLY_STR:
         return " STR ";
      case APPLY_DEX:
         return " DEX ";
      case APPLY_INT:
         return " INT ";
      case APPLY_WIS:
         return " WIS ";
      case APPLY_CON:
         return " CON ";
      case APPLY_CHA:
         return " CHA ";
      case APPLY_LCK:
         return " LCK  ";
      case APPLY_SEX:
         return " SEX  ";
      case APPLY_CLASS:
         return " CLASS";
      case APPLY_LEVEL:
         return " LVL  ";
      case APPLY_AGE:
         return " AGE  ";
      case APPLY_MANA:
         return " MANA ";
      case APPLY_HIT:
         return " HV   ";
      case APPLY_MOVE:
         return " MOVE ";
      case APPLY_GOLD:
         return " GOLD ";
      case APPLY_EXP:
         return " EXP  ";
      case APPLY_AC:
         return " AC   ";
      case APPLY_HITROLL:
         return " HITRL";
      case APPLY_DAMROLL:
         return " DAMRL";
      case APPLY_SAVING_STR:
         return "STR SAV";
      case APPLY_SAVING_DEX:
         return "DEX SAV";
      case APPLY_SAVING_CON:
         return "CON SAV";
      case APPLY_SAVING_INT:
         return "INT SAV";
      case APPLY_SAVING_WIS:
         return "WIS SAV";
      case APPLY_SAVING_CHA:
         return "CHA SAV";
      case APPLY_HEIGHT:
         return "HEIGHT";
      case APPLY_WEIGHT:
         return "WEIGHT";
      case APPLY_AFFECT:
         return "AFF BY";
      case APPLY_RESISTANT:
         return "RESIST";
      case APPLY_IMMUNE:
         return "IMMUNE";
      case APPLY_SUSCEPTIBLE:
         return "SUSCEPT";
      case APPLY_WEAPONSPELL:
         return " WEAPON";
      case APPLY_BACKSTAB:
         return "BACKSTB";
      case APPLY_PICK:
         return " PICK  ";
      case APPLY_TRACK:
         return " TRACK ";
      case APPLY_STEAL:
         return " STEAL ";
      case APPLY_SNEAK:
         return " SNEAK ";
      case APPLY_HIDE:
         return " HIDE  ";
      case APPLY_PALM:
         return " PALM  ";
      case APPLY_DETRAP:
         return " DETRAP";
      case APPLY_DODGE:
         return " DODGE ";
      case APPLY_PEEK:
         return " PEEK  ";
      case APPLY_SCAN:
         return " SCAN  ";
      case APPLY_GOUGE:
         return " GOUGE ";
      case APPLY_SEARCH:
         return " SEARCH";
      case APPLY_MOUNT:
         return " MOUNT ";
      case APPLY_DISARM:
         return " DISARM";
      case APPLY_KICK:
         return " KICK  ";
      case APPLY_PARRY:
         return " PARRY ";
      case APPLY_BASH:
         return " BASH  ";
      case APPLY_STUN:
         return " STUN  ";
      case APPLY_PUNCH:
         return " PUNCH ";
      case APPLY_CLIMB:
         return " CLIMB ";
      case APPLY_GRIP:
         return " GRIP  ";
      case APPLY_SCRIBE:
         return " SCRIBE";
      case APPLY_BREW:
         return " BREW  ";
      case APPLY_WEARSPELL:
         return " WEAR  ";
      case APPLY_REMOVESPELL:
         return " REMOVE";
      case APPLY_EMOTION:
         return "EMOTION";
      case APPLY_MENTALSTATE:
         return " MENTAL";
      case APPLY_STRIPSN:
         return " DISPEL";
      case APPLY_REMOVE:
         return " REMOVE";
      case APPLY_DIG:
         return " DIG   ";
      case APPLY_FULL:
         return " HUNGER";
      case APPLY_THIRST:
         return " THIRST";
      case APPLY_DRUNK:
         return " DRUNK ";
      case APPLY_BLOOD:
         return " BLOOD ";
      case APPLY_COOK:
         return " COOK  ";
      case APPLY_RECURRINGSPELL:
         return " RECURR";
      case APPLY_CONTAGIOUS:
         return "CONTGUS";
      case APPLY_ODOR:
         return " ODOR  ";
      case APPLY_ROOMFLAG:
         return " RMFLG ";
      case APPLY_SECTORTYPE:
         return " SECTOR";
      case APPLY_ROOMLIGHT:
         return " LIGHT ";
      case APPLY_TELEVNUM:
         return " TELEVN";
      case APPLY_TELEDELAY:
         return " TELEDY";
      case APPLY_SILVER:      return " SILVER";
      case APPLY_COPPER:      return " COPPER";
      case APPLY_BASE_AC:     return "BASE AC";
      
   };

   bug( "Affect_location_name: unknown location %d.", location );
   return "(?)";
}

const char *get_class( CHAR_DATA * ch )
{
   if( IS_NPC( ch ) && ch->Class < MAX_NPC_CLASS && ch->Class >= 0 )
      return ( npc_class[ch->Class] );
   else if( !IS_NPC( ch ) && ch->Class < MAX_PC_CLASS && ch->Class >= 0 )
      return class_table[ch->Class]->who_name;
   return ( "Unknown" );
}


const char *get_race( CHAR_DATA * ch )
{
   if( ch->race < MAX_PC_RACE && ch->race >= 0 )
      return ( race_table[ch->race]->race_name );
   if( ch->race < MAX_NPC_RACE && ch->race >= 0 )
      return ( npc_race[ch->race] );
   return ( "Unknown" );
}

/*								-Thoric
 * Display your current exp, level, and surrounding level exp requirements
 */
void do_level( CHAR_DATA* ch, const char* argument)
{
   char buf[MAX_STRING_LENGTH];
   char buf2[MAX_STRING_LENGTH];
   int x, lowlvl, hilvl;

   if( ch->level == 1 )
      lowlvl = 1;
   else
      lowlvl = UMAX( 2, ch->level - 5 );
   hilvl = URANGE( ch->level, ch->level + 5, MAX_LEVEL );
   set_char_color( AT_SCORE, ch );
   ch_printf( ch, "\r\nExperience required, levels %d to %d:\r\n______________________________________________\r\n\r\n",
              lowlvl, hilvl );
   snprintf( buf, MAX_STRING_LENGTH, " exp  (Current: %12s)", num_punct( ch->exp ) );
   snprintf( buf2, MAX_STRING_LENGTH, " exp  (Needed:  %12s)", num_punct( exp_level( ch, ch->level + 1 ) - ch->exp ) );
   for( x = lowlvl; x <= hilvl; x++ )
      ch_printf( ch, " (%2d) %12s%s\r\n", x, num_punct( exp_level( ch, x ) ),
                 ( x == ch->level ) ? buf : ( x == ch->level + 1 ) ? buf2 : " exp" );
   send_to_char( "______________________________________________\r\n", ch );
}

/*
 * New Advance Level command for D&D 5e Rules
 */

void do_advance_level( CHAR_DATA *ch, const char *argument )
{
   int add_hp;
   
/*   if( ch->exp <= exp_level( ch, ch->level + 1 ) )
   {
      send_to_char( "You do not have enough experience to advance a level.\r\n", ch );
      return;
   } */
   
   /* Advancement must be done by a teacher of your subclass and a level higher than yours.
    * Coding in later to allow for testing.
    * - Seikyr
    */

   add_hp = con_app[get_curr_con( ch )].bonus + number_range( class_table[ch->Class]->hp_min, class_table[ch->Class]->hp_max );
   add_hp = UMAX( 1, add_hp );
   ch->max_hit += add_hp;
   ch->level += 1;
   
   ch_printf( ch, "&G-=-=-=-=-=-=-=-=-&g[ &YLEVEL UP &g]&G-=-=-=-=-=-=-=-=-\r\n" );
   ch_printf( ch, "&wYou achieved level %d! You gain %d hit points.\r\n", ch->level, add_hp );
   switch( ch->Class )
   {
      case CLASS_FIGHTER:
         if( ch->level == 2 || ch->level == 20 )
         {
            send_to_char( "&WYou may choose a fighting style from the following options:\r\n ", ch );
            send_to_char( "&C1&c) &CArchery&w, &C2&c)&CDefense&w, &C3&c)&CDueling&w, &C4&c)&CGreat Weapon&w, &C5&c)&CProtection&w, &C6&c)&CTwo-Weapon\r\n", ch );
            send_to_char( "Please make a selection:\r\n", ch );
            ch->desc->connected = CON_ADVANCE_LEVEL;
            return;
         }
         if( ch->level == 6 )
         {
            send_to_char( "&WYou are now of the subclass Champion.\r\n", ch );
            xTOGGLE_BIT( ch->subclasses, SUBCLASS_CHAMPION );
         }
         if( ch->level == 8 || ch->level == 16 || ch->level == 24 || ch->level == 28 || ch->level == 32 || ch->level == 40 )
         {
            if( ch->level == 40 )
            {
               send_to_char( "&WYou gain the ability to make four attacks per turn.\r\n", ch );
               ch->pcdata->learned[gsn_fourth_attack] = 100;
            }
            ch->statpoints = 2;
            send_to_char( "&WYou may now choose an ability score to improve. You have two points to distribute as you see fit, up to a max of 20.\r\n", ch );
            ch_printf( ch, "&C1&c) &W%d&R+1 &WStrength\r\n&C2&c) &W%d&R+1 &WDexterity\r\n&C3&c) &W%d&R+1 &WIntelligence\r\n&C4&c) &W%d&R+1 &WWisdom\r\n&C5&c) &W%d&R+1 &WConstitution\r\n&C6&c)&W %d&R+1 &WCharisma\r\n",
                      ch->perm_str, ch->perm_dex, ch->perm_int, ch->perm_wis, ch->perm_con, ch->perm_cha );
            send_to_char( "Please make a selection:\r\n", ch );
            ch->desc->connected = CON_ADVANCE_LEVEL;
            return;
         }
         if( ch->level == 10 )
         {
            send_to_char( "&WYou gain the ability to make two attacks per turn.\r\n", ch );
            ch->pcdata->learned[gsn_second_attack] = 100;
         }
         if( ch->level == 14 )
         {
            send_to_char( "&WYou gain the &Gremarkable athlete &Wability, which allows you to add half your proficiency bonus to any Strength, Dexterity, or Constitution check.\r\n", ch );
            ch->pcdata->learned[gsn_remarkable_athlete] == 100;
         }
         if( ch->level == 18 )
         {
            send_to_char( "&WYou gain the &Gindomitable&W ability, which allows you to reroll a saving throw that you fail.\r\n", ch );
            ch->pcdata->learned[gsn_indomitable] == 100;
         }
         if( ch->level == 22 )
         {
            send_to_char( "&WYou gain the ability to make three attacks per turn.\r\n", ch );
            ch->pcdata->learned[gsn_third_attack] = 100;
         }
         if( ch->level == 36 )
         {
            ch_printf( ch, "&WYou gain the &Gsurvivor&W ability, which regains &G%d &Whit points every turn.\r\n", 5+con_app[get_curr_con( ch )].bonus );
            ch->pcdata->learned[gsn_survivor] = 100;
         }
   }
   return;
}

/* 1997, Blodkai */
void do_remains( CHAR_DATA* ch, const char* argument)
{
   char buf[MAX_STRING_LENGTH];
   OBJ_DATA *obj;
   bool found = FALSE;

   if( IS_NPC( ch ) )
      return;

   set_char_color( AT_MAGIC, ch );
   if( !ch->pcdata->deity )
   {
      send_to_pager( "&WYou have no deity from which to seek such assistance...\r\n", ch );
      return;
   }

   if( ch->pcdata->favor < ch->level * 2 )
   {
      send_to_pager( "&WYour current favor is insufficient for such assistance...\r\n", ch );
      return;
   }

   pager_printf( ch, "%s appears in a vision, revealing that your remains... ", ch->pcdata->deity->name );
   snprintf( buf, MAX_STRING_LENGTH, "the corpse of %s", ch->name );
   for( obj = first_object; obj; obj = obj->next )
   {
      if( obj->in_room && !str_cmp( buf, obj->short_descr ) && ( obj->pIndexData->vnum == OBJ_VNUM_CORPSE_PC ) )
      {
         found = TRUE;
         pager_printf( ch, "\r\n  - at %s will endure for %d ticks", obj->in_room->name, obj->timer );
      }
   }
   if( !found )
      send_to_pager( " no longer exist.\r\n", ch );
   else
   {
      send_to_pager( "\r\n", ch );
      ch->pcdata->favor -= ch->level * 2;
   }
   return;
}

/* Affects-at-a-glance, Blodkai */
void do_affected( CHAR_DATA* ch, const char* argument)
{
   char arg[MAX_INPUT_LENGTH];
   int affnum = 0;
   AFFECT_DATA *paf;
   SKILLTYPE *skill;

   if( IS_NPC( ch ) )
      return;

   set_char_color( AT_SCORE, ch );

   argument = one_argument( argument, arg );
   if( !str_cmp( arg, "by" ) )
   {
      send_to_char_color( "\r\n&CImbued with:\r\n", ch );
      ch_printf_color( ch, "   &w%s\r\n", !xIS_EMPTY( ch->affected_by ) ? affect_bit_name( &ch->affected_by ) : "nothing" );
      if( ch->level >= 20 )
      {
         send_to_char( "\r\n", ch );
            send_to_char_color( "&CYou are resistant to:\r\n", ch );
            ch_printf_color( ch, "   &w%s\r\n", ext_flag_string( &ch->resistant, ris_flags ) );
            send_to_char_color( "&CYou are immune to:\r\n", ch );
            ch_printf_color( ch, "&w   %s\r\n", ext_flag_string( &ch->immune, ris_flags ) );
            send_to_char_color( "&CYou are susceptible to:\r\n ", ch );
            ch_printf_color( ch, "&w   %s\r\n", ext_flag_string( &ch->susceptible, ris_flags ) );
      }
      return;
   }

   if( !ch->first_affect )
   {
      send_to_char_color( "\r\n&CNo cantrip or skill affects you.\r\n", ch );
   }
   else
   {
      char mod[MAX_INPUT_LENGTH];
      send_to_char( "&z-=&W( &CAffects Summary &W)&z=-&w\r\n", ch );
      
      send_to_char( "\r\n", ch );
      for( paf = ch->first_affect; paf; paf = paf->next )
         if( ( skill = get_skilltype( paf->type ) ) != NULL )
         {
            ++affnum;
            if( paf->location == APPLY_AFFECT || paf->location == APPLY_EXT_AFFECT )
               mudstrlcpy( mod, a_flags[paf->modifier], MIL );
            else if( paf->location == APPLY_RESISTANT || paf->location == APPLY_IMMUNE || paf->location == APPLY_SUSCEPTIBLE )
               mudstrlcpy( mod, ris_flags[paf->modifier], MIL );
            else
               snprintf( mod, MIL, "%d", paf->modifier );
            if( ch->level > LEVEL_AVATAR * 0.40 )
            {
               ch_printf( ch, "&W%d&z> &BSpell:&w %-18s &W- &PModifies&w %-18s &Bby &Y%-18s&B for&R %-4d&B rounds.&D\r\n",
                           affnum, skill->name, a_types[paf->location], mod, paf->duration );
            }
            else if( ch->level > ( LEVEL_AVATAR * 0.20 ) && ch->level <= ( LEVEL_AVATAR * 0.40 ) )
            {
               ch_printf( ch, "&W%d&z> &BSpell:&w %-18s &W- &PModifies&w %-18s&B by &Y%-18s&D\r\n", affnum, skill->name, a_types[paf->location], mod );
            }
            else if( ch->level > ( LEVEL_AVATAR * 0.10 ) && ch->level <= ( LEVEL_AVATAR * 0.20 ) )
            {
               ch_printf( ch, "&W%d&z> &BSpell:&w %-18s &W- &PModifies&w %-18s&D\r\n", affnum, skill->name, a_types[paf->location] );
            }
         }
   }
   return;
}

void do_inventory( CHAR_DATA* ch, const char* argument)
{
   CHAR_DATA *victim;

   if( !argument || argument[0] == '\0' || !IS_IMMORTAL( ch ) )
      victim = ch;
   else
   {
      if( !( victim = get_char_world( ch, argument ) ) )
      {
         ch_printf( ch, "There is nobody named %s online.\r\n", argument );
         return;
      }
   }

   if( victim != ch )
      ch_printf( ch, "&R%s is carrying:\r\n", IS_NPC( victim ) ? victim->short_descr : victim->name );
   else
      send_to_char( "&RYou are carrying:\r\n", ch );

   show_list_to_char( victim->first_carrying, ch, TRUE, TRUE );
   return;
}

void do_equipment( CHAR_DATA* ch, const char* argument)
{
   CHAR_DATA *victim = ch;
   OBJ_DATA *obj;
   int iWear;
   bool found;

   if( argument[0] == '\0' || get_trust( ch ) <= LEVEL_GOD )
      victim = ch;
   else
   {
      if( ( victim = get_char_world( ch, argument ) ) == NULL )
      {
         send_to_char( "They're not here.\r\n", ch );
         return;
      }
   }

   if( victim != ch )
      ch_printf( ch, "&R%s is using:\r\n", IS_NPC( victim ) ? victim->short_descr : victim->name );
   else
      send_to_char( "&RYou are using:\r\n", ch );

   found = FALSE;
   set_char_color( AT_OBJECT, ch );
   for( iWear = 0; iWear < MAX_WEAR; iWear++ )
   {
      for( obj = victim->first_carrying; obj; obj = obj->next_content )
      {
         if( obj->wear_loc == iWear )
         {
/*            if( ( !IS_NPC( victim ) ) && ( victim->race > 0 ) && ( victim->race < MAX_PC_RACE ) )
               send_to_char( race_table[victim->race]->where_name[iWear], ch );
            else */
               send_to_char( where_name[iWear], ch );
            if( can_see_obj( ch, obj ) )
            {
               send_to_char( format_obj_to_char( obj, ch, TRUE ), ch );
               send_to_char( "\n\r", ch );
            }
            else
               send_to_char( "Something.\r\n", ch );
            found = TRUE;
         }         
      }
   }

   if( !found )
      send_to_char( "Nothing.\r\n", ch ); 
}

void set_title( CHAR_DATA * ch, const char *title )
{
   char buf[MAX_STRING_LENGTH];

   if( IS_NPC( ch ) )
   {
      bug( "%s: NPC.", __func__ );
      return;
   }

   if( isalpha( title[0] ) || isdigit( title[0] ) )
   {
      buf[0] = ' ';
      mudstrlcpy( buf + 1, title, MAX_STRING_LENGTH - 1 );
   }
   else
      mudstrlcpy( buf, title, MAX_STRING_LENGTH );

   STRFREE( ch->pcdata->title );
   ch->pcdata->title = STRALLOC( buf );
}

void do_title( CHAR_DATA* ch, const char* argument)
{
   if( IS_NPC( ch ) )
      return;

   set_char_color( AT_SCORE, ch );

   if( IS_SET( ch->pcdata->flags, PCFLAG_NOTITLE ) )
   {
      set_char_color( AT_IMMORT, ch );
      send_to_char( "The Gods prohibit you from changing your title.\r\n", ch );
      return;
   }

   if( argument[0] == '\0' )
   {
      send_to_char( "Change your title to what?\r\n", ch );
      return;
   }

   char title[50];
   mudstrlcpy(title, argument, 50);

   smash_tilde( title );
   set_title( ch, title );
   send_to_char( "Ok.\r\n", ch );
}

void do_homepage( CHAR_DATA* ch, const char* argument)
{
   char buf[MAX_STRING_LENGTH];

   if( IS_NPC( ch ) )
      return;

   if( IS_SET( ch->pcdata->flags, PCFLAG_NOHOMEPAGE ) )
   {
      send_to_char( "The Gods prohibit you from changing your homepage.\r\n", ch );
      return;
   }

   if( argument[0] == '\0' )
   {
      if( !ch->pcdata->homepage )
         ch->pcdata->homepage = str_dup( "" );
      ch_printf( ch, "Your homepage is: %s\r\n", show_tilde( ch->pcdata->homepage ) );
      return;
   }

   if( !str_cmp( argument, "clear" ) )
   {
      if( ch->pcdata->homepage )
         DISPOSE( ch->pcdata->homepage );
      ch->pcdata->homepage = str_dup( "" );
      send_to_char( "Homepage cleared.\r\n", ch );
      return;
   }

   if( strstr( argument, "://" ) )
      mudstrlcpy( buf, argument, MAX_STRING_LENGTH );
   else
      snprintf( buf, MAX_STRING_LENGTH, "http://%s", argument );
   if( strlen( buf ) > 70 )
      buf[70] = '\0';

   hide_tilde( buf );
   if( ch->pcdata->homepage )
      DISPOSE( ch->pcdata->homepage );
   ch->pcdata->homepage = str_dup( buf );
   send_to_char( "Homepage set.\r\n", ch );
}

/*
 * Set your personal description				-Thoric
 */
void do_description( CHAR_DATA* ch, const char* argument)
{
   if( IS_NPC( ch ) )
   {
      send_to_char( "Monsters are too dumb to do that!\r\n", ch );
      return;
   }

   if( IS_SET( ch->pcdata->flags, PCFLAG_NODESC ) )
   {
      send_to_char( "You cannot set your description.\r\n", ch );
      return;
   }

   if( !ch->desc )
   {
      bug( "%s: no descriptor", __func__ );
      return;
   }

   switch ( ch->substate )
   {
      default:
         bug( "%s: illegal substate", __func__ );
         return;

      case SUB_RESTRICTED:
         send_to_char( "You cannot use this command from within another command.\r\n", ch );
         return;

      case SUB_NONE:
         ch->substate = SUB_PERSONAL_DESC;
         ch->dest_buf = ch;
         start_editing( ch, ch->description );
         return;

      case SUB_PERSONAL_DESC:
         STRFREE( ch->description );
         ch->description = copy_buffer( ch );
         stop_editing( ch );
         return;
   }
}

/* Ripped off do_description for whois bio's -- Scryn*/
void do_bio( CHAR_DATA* ch, const char* argument)
{
   if( IS_NPC( ch ) )
   {
      send_to_char( "Mobs cannot set a bio.\r\n", ch );
      return;
   }

   if( IS_SET( ch->pcdata->flags, PCFLAG_NOBIO ) )
   {
      set_char_color( AT_RED, ch );
      send_to_char( "The gods won't allow you to do that!\r\n", ch );
      return;
   }

   if( !ch->desc )
   {
      bug( "%s: no descriptor", __func__ );
      return;
   }

   switch ( ch->substate )
   {
      default:
         bug( "%s: illegal substate", __func__ );
         return;

      case SUB_RESTRICTED:
         send_to_char( "You cannot use this command from within another command.\r\n", ch );
         return;

      case SUB_NONE:
         ch->substate = SUB_PERSONAL_BIO;
         ch->dest_buf = ch;
         start_editing( ch, ch->pcdata->bio );
         return;

      case SUB_PERSONAL_BIO:
         STRFREE( ch->pcdata->bio );
         ch->pcdata->bio = copy_buffer( ch );
         stop_editing( ch );
         return;
   }
}

/*
 * New stat and statreport command coded by Morphina
 * Bug fixes by Shaddai
 */
void do_statreport( CHAR_DATA* ch, const char* argument)
{
   char buf[MAX_STRING_LENGTH];

   if( IS_NPC( ch ) )
   {
      send_to_char( "Huh?\r\n", ch );
      return;
   }

   if( IS_VAMPIRE( ch ) )
   {
      ch_printf( ch, "You report: %d/%d hp %d/%d blood %d/%d mv %d xp.\r\n",
                 ch->hit, ch->max_hit, ch->pcdata->condition[COND_BLOODTHIRST],
                 10 + ch->level, ch->move, ch->max_move, ch->exp );
      snprintf( buf, MAX_STRING_LENGTH, "$n reports: %d/%d hp %d/%d blood %d/%d mv %d xp.",
                ch->hit, ch->max_hit, ch->pcdata->condition[COND_BLOODTHIRST],
                10 + ch->level, ch->move, ch->max_move, ch->exp );
      act( AT_REPORT, buf, ch, NULL, NULL, TO_ROOM );
   }
   else
   {
      ch_printf( ch, "You report: %d/%d hp %d/%d mana %d/%d mv %d xp.\r\n",
                 ch->hit, ch->max_hit, ch->mana, ch->max_mana, ch->move, ch->max_move, ch->exp );
      snprintf( buf, MAX_STRING_LENGTH, "$n reports: %d/%d hp %d/%d mana %d/%d mv %d xp.",
                ch->hit, ch->max_hit, ch->mana, ch->max_mana, ch->move, ch->max_move, ch->exp );
      act( AT_REPORT, buf, ch, NULL, NULL, TO_ROOM );
   }

   ch_printf( ch, "Your base stats:    %-2d str %-2d wis %-2d int %-2d dex %-2d con %-2d cha %-2d lck.\r\n",
              ch->perm_str, ch->perm_wis, ch->perm_int, ch->perm_dex, ch->perm_con, ch->perm_cha, ch->perm_lck );
   snprintf( buf, MAX_STRING_LENGTH, "$n's base stats:    %-2d str %-2d wis %-2d int %-2d dex %-2d con %-2d cha %-2d lck.",
             ch->perm_str, ch->perm_wis, ch->perm_int, ch->perm_dex, ch->perm_con, ch->perm_cha, ch->perm_lck );
   act( AT_REPORT, buf, ch, NULL, NULL, TO_ROOM );

   ch_printf( ch, "Your current stats: %-2d str %-2d wis %-2d int %-2d dex %-2d con %-2d cha %-2d lck.\r\n",
              get_curr_str( ch ), get_curr_wis( ch ), get_curr_int( ch ),
              get_curr_dex( ch ), get_curr_con( ch ), get_curr_cha( ch ), get_curr_lck( ch ) );
   snprintf( buf, MAX_STRING_LENGTH, "$n's current stats: %-2d str %-2d wis %-2d int %-2d dex %-2d con %-2d cha %-2d lck.",
             get_curr_str( ch ), get_curr_wis( ch ), get_curr_int( ch ),
             get_curr_dex( ch ), get_curr_con( ch ), get_curr_cha( ch ), get_curr_lck( ch ) );
   act( AT_REPORT, buf, ch, NULL, NULL, TO_ROOM );
   return;
}

void do_stat( CHAR_DATA* ch, const char* argument)
{
   if( IS_NPC( ch ) )
   {
      send_to_char( "Huh?\r\n", ch );
      return;
   }

   if( IS_VAMPIRE( ch ) )
      ch_printf( ch, "You report: %d/%d hp %d/%d blood %d/%d mv %d xp.\r\n",
                 ch->hit, ch->max_hit, ch->pcdata->condition[COND_BLOODTHIRST],
                 10 + ch->level, ch->move, ch->max_move, ch->exp );
   else
      ch_printf( ch, "You report: %d/%d hp %d/%d mana %d/%d mv %d xp.\r\n",
                 ch->hit, ch->max_hit, ch->mana, ch->max_mana, ch->move, ch->max_move, ch->exp );

   ch_printf( ch, "Your base stats:    %-2d str %-2d wis %-2d int %-2d dex %-2d con %-2d cha %-2d lck.\r\n",
              ch->perm_str, ch->perm_wis, ch->perm_int, ch->perm_dex, ch->perm_con, ch->perm_cha, ch->perm_lck );

   ch_printf( ch, "Your current stats: %-2d str %-2d wis %-2d int %-2d dex %-2d con %-2d cha %-2d lck.\r\n",
              get_curr_str( ch ), get_curr_wis( ch ), get_curr_int( ch ),
              get_curr_dex( ch ), get_curr_con( ch ), get_curr_cha( ch ), get_curr_lck( ch ) );
   return;
}

void do_report( CHAR_DATA* ch, const char* argument)
{
   char buf[MAX_INPUT_LENGTH];

   if( IS_NPC( ch ) && ch->fighting )
      return;

   if( IS_AFFECTED( ch, AFF_POSSESS ) )
   {
      send_to_char( "You can't do that in your current state of mind!\r\n", ch );
      return;
   }


   if( IS_VAMPIRE( ch ) )
      ch_printf( ch,
                 "You report: %d/%d hp %d/%d blood %d/%d mv %d xp.\r\n",
                 ch->hit, ch->max_hit,
                 ch->pcdata->condition[COND_BLOODTHIRST], 10 + ch->level, ch->move, ch->max_move, ch->exp );
   else
      ch_printf( ch,
                 "You report: %d/%d hp %d/%d mana %d/%d mv %d xp.\r\n",
                 ch->hit, ch->max_hit, ch->mana, ch->max_mana, ch->move, ch->max_move, ch->exp );

   if( IS_VAMPIRE( ch ) )
      snprintf( buf, MAX_INPUT_LENGTH, "$n reports: %d/%d hp %d/%d blood %d/%d mv %d xp.\r\n",
                ch->hit, ch->max_hit,
                ch->pcdata->condition[COND_BLOODTHIRST], 10 + ch->level, ch->move, ch->max_move, ch->exp );
   else
      snprintf( buf, MAX_INPUT_LENGTH, "$n reports: %d/%d hp %d/%d mana %d/%d mv %d xp.",
                ch->hit, ch->max_hit, ch->mana, ch->max_mana, ch->move, ch->max_move, ch->exp );

   act( AT_REPORT, buf, ch, NULL, NULL, TO_ROOM );

   return;
}

void do_fprompt( CHAR_DATA* ch, const char* argument)
{
   char arg[MAX_INPUT_LENGTH];

   set_char_color( AT_GREY, ch );

   if( IS_NPC( ch ) )
   {
      send_to_char( "NPC's can't change their prompt..\r\n", ch );
      return;
   }

   smash_tilde( argument );
   one_argument( argument, arg );
   if( !*arg || !str_cmp( arg, "display" ) )
   {
      send_to_char( "Your current fighting prompt string:\r\n", ch );
      set_char_color( AT_WHITE, ch );
      ch_printf( ch, "%s\r\n", !str_cmp( ch->pcdata->fprompt, "" ) ? "(default prompt)" : ch->pcdata->fprompt );
      set_char_color( AT_GREY, ch );
      send_to_char( "Type 'help prompt' for information on changing your prompt.\r\n", ch );
      return;
   }

   send_to_char( "Replacing old prompt of:\r\n", ch );
   set_char_color( AT_WHITE, ch );
   ch_printf( ch, "%s\r\n", !str_cmp( ch->pcdata->fprompt, "" ) ? "(default prompt)" : ch->pcdata->fprompt );
   if( ch->pcdata->fprompt )
      STRFREE( ch->pcdata->fprompt );

   char prompt[128];
   mudstrlcpy(prompt, argument, 128);

   /*
    * Can add a list of pre-set prompts here if wanted.. perhaps
    * 'prompt 1' brings up a different, pre-set prompt 
    */
   if( !str_cmp( arg, "default" ) )
      ch->pcdata->fprompt = STRALLOC( "" );
   else if( !str_cmp( arg, "none" ) )
      ch->pcdata->fprompt = STRALLOC( ch->pcdata->prompt );
   else
      ch->pcdata->fprompt = STRALLOC( argument );
   return;
}

void do_prompt( CHAR_DATA* ch, const char* argument)
{
   char arg[MAX_INPUT_LENGTH];

   set_char_color( AT_GREY, ch );

   if( IS_NPC( ch ) )
   {
      send_to_char( "NPC's can't change their prompt..\r\n", ch );
      return;
   }
   smash_tilde( argument );
   one_argument( argument, arg );
   if( !*arg || !str_cmp( arg, "display" ) )
   {
      send_to_char( "Your current prompt string:\r\n", ch );
      set_char_color( AT_WHITE, ch );
      ch_printf( ch, "%s\r\n", !str_cmp( ch->pcdata->prompt, "" ) ? "(default prompt)" : ch->pcdata->prompt );
      set_char_color( AT_GREY, ch );
      send_to_char( "Type 'help prompt' for information on changing your prompt.\r\n", ch );
      return;
   }
   send_to_char( "Replacing old prompt of:\r\n", ch );
   set_char_color( AT_WHITE, ch );
   ch_printf( ch, "%s\r\n", !str_cmp( ch->pcdata->prompt, "" ) ? "(default prompt)" : ch->pcdata->prompt );
   if( ch->pcdata->prompt )
      STRFREE( ch->pcdata->prompt );

   char prompt[128];
   mudstrlcpy(prompt, argument, 128);

   /*
    * Can add a list of pre-set prompts here if wanted.. perhaps
    * 'prompt 1' brings up a different, pre-set prompt 
    */
   if( !str_cmp( arg, "default" ) )
      ch->pcdata->prompt = STRALLOC( "" );
   else if( !str_cmp( arg, "fprompt" ) )
      ch->pcdata->prompt = STRALLOC( ch->pcdata->fprompt );
   else
      ch->pcdata->prompt = STRALLOC( argument );
   return;
}

void do_compass( CHAR_DATA *ch, const char *argument )
{
   char arg[MAX_INPUT_LENGTH];

   one_argument( argument, arg );

   if( arg[0] == '\0' )
   {
      if( xIS_SET( ch->act, PLR_COMPASS ) )
      {
         xREMOVE_BIT( ch->act, PLR_COMPASS );
         send_to_char( "Compass is now off.\r\n", ch );
      }
      else
      {
         xSET_BIT( ch->act, PLR_COMPASS );
         do_look( ch, "auto" );
      }
   }
}

/*
 *  Command to show current favor by Edmond
 */
void do_favor( CHAR_DATA * ch, const char *argument )
{
   char buf[MAX_STRING_LENGTH];

   if( IS_NPC( ch ) )
   {
      send_to_char( "Huh?\r\n", ch );
      return;
   }

   set_char_color( AT_GREEN, ch );
   if( !ch->pcdata->deity )
      mudstrlcpy( buf, "N/A", MAX_STRING_LENGTH );
   else if( ch->pcdata->favor > 2250 )
      mudstrlcpy( buf, "loved", MAX_STRING_LENGTH );
   else if( ch->pcdata->favor > 2000 )
      mudstrlcpy( buf, "cherished", MAX_STRING_LENGTH );
   else if( ch->pcdata->favor > 1750 )
      mudstrlcpy( buf, "honored", MAX_STRING_LENGTH );
   else if( ch->pcdata->favor > 1500 )
      mudstrlcpy( buf, "praised", MAX_STRING_LENGTH );
   else if( ch->pcdata->favor > 1250 )
      mudstrlcpy( buf, "favored", MAX_STRING_LENGTH );
   else if( ch->pcdata->favor > 1000 )
      mudstrlcpy( buf, "respected", MAX_STRING_LENGTH );
   else if( ch->pcdata->favor > 750 )
      mudstrlcpy( buf, "liked", MAX_STRING_LENGTH );
   else if( ch->pcdata->favor > 250 )
      mudstrlcpy( buf, "tolerated", MAX_STRING_LENGTH );
   else if( ch->pcdata->favor > -250 )
      mudstrlcpy( buf, "ignored", MAX_STRING_LENGTH );
   else if( ch->pcdata->favor > -750 )
      mudstrlcpy( buf, "shunned", MAX_STRING_LENGTH );
   else if( ch->pcdata->favor > -1000 )
      mudstrlcpy( buf, "disliked", MAX_STRING_LENGTH );
   else if( ch->pcdata->favor > -1250 )
      mudstrlcpy( buf, "dishonored", MAX_STRING_LENGTH );
   else if( ch->pcdata->favor > -1500 )
      mudstrlcpy( buf, "disowned", MAX_STRING_LENGTH );
   else if( ch->pcdata->favor > -1750 )
      mudstrlcpy( buf, "abandoned", MAX_STRING_LENGTH );
   else if( ch->pcdata->favor > -2000 )
      mudstrlcpy( buf, "despised", MAX_STRING_LENGTH );
   else if( ch->pcdata->favor > -2250 )
      mudstrlcpy( buf, "hated", MAX_STRING_LENGTH );
   else
      mudstrlcpy( buf, "damned", MAX_STRING_LENGTH );

   ch_printf( ch, "%s considers you to be %s.\n\r", ch->pcdata->deity->name, buf );
   return;
}

/*
 * New Greet System by Seikyr
 */

void do_greet( CHAR_DATA * ch, const char *argument )
{
   char arg[MAX_INPUT_LENGTH];
   CHAR_DATA *victim;
   GREET_DATA *greet;
   
   argument = one_argument( argument, arg );

   if( arg[0] == '\0' )
   {
      send_to_char( "Greet whom?\r\n", ch );
      return;
   }
   
   if( ( victim = get_char_room( ch, arg ) ) == NULL )
   {
      send_to_char( "That player is not here.\r\n", ch );
      return;
   }

   if( IS_NPC( victim ) )
   {
      send_to_char( "Not on NPC's.\r\n", ch );
      return;
   }

   if( IS_IMMORTAL( victim ) )
   {
      send_to_char( "You can't greet such a godly presence.\r\n", ch );
      return;
   }
   
   for( greet = victim->first_greet; greet; greet = greet->next )
   {
      if( greet->name == ch->name )
         send_to_char( "They already know who you are.\r\n", ch );
         return;
   }
   
   ch_printf( ch, "You greet %s.\r\n", victim->name );
   ch_printf( victim, "%s greets you.\r\n", ch->name );
   CREATE( greet, GREET_DATA, 1 );
   greet->name = STRALLOC( ch->name );
   LINK( greet, victim->first_greet, victim->last_greet, next, prev );
   save_char_obj( victim );
}

void do_adjective( CHAR_DATA * ch, const char *argument )
{
   char buf[MAX_STRING_LENGTH];
   char arg[MAX_INPUT_LENGTH];
   
   one_argument( argument, arg );
   
   if ( arg[0] == '\0' )
   {
      ch_printf( ch, "Your current adjective is: %s.\r\n", ch->adjective );
      return;
   }
   
   if( !str_cmp( arg, "clear" ) )
   {
      snprintf( buf, MAX_STRING_LENGTH, "An ordinary %s %s", ch->sex == SEX_FEMALE ? "female" : "male", race_table[ch->race]->race_name );
      STRFREE( ch->adjective );
      ch->adjective = STRALLOC( strlower( buf ) );
      send_to_char( "Adjective cleared.\r\n", ch );
   }
   else
   {
      snprintf( buf, MAX_STRING_LENGTH, "%s %s %s", aoran( argument ), ch->sex == SEX_FEMALE ? "female" : "male", race_table[ch->race]->race_name );
      STRFREE( ch->adjective );
      ch->adjective = STRALLOC( strlower( buf ) );
      send_to_char( "Adjective set.\r\n", ch );
      return;
   }
}

void do_abilities( CHAR_DATA *ch, const char *argument )
{
   char arg[MAX_INPUT_LENGTH];
   char buf[MAX_STRING_LENGTH];
   COOLDOWN_DATA *skill;
   MULTICLASS_DATA *imc;
   int points = 0;
   
   one_argument( argument, arg );
   if( IS_NPC( ch ) )
   {
      send_to_char( "You don't have any abilities!\r\n", ch );
      return;
   }
   
   if( arg[0] == '\0' )
   {
      
      ch_printf( ch, "  &CAbilities for &w%s&C, Level &w%d &C%s %s\r\n",
                ch->name, ch->level, capitalize( ext_flag_string( &ch->subrace, subrace_flags ) ), get_race( ch ) );
      ch_printf( ch, "   &CClasses:\r\n" );
      for( imc = ch->first_multiclass; imc; imc = imc->next )
      {
         ch_printf( ch, " &W%s&z: &C%d\t", capitalize( npc_class[imc->classname] ), imc->level );
      }
      send_to_char( "\r\n", ch );
      send_to_char( "&B|----------------------------------------------------------|\r\n", ch );
      ch_printf( ch, "  &CSubclasses&c: &w%s\r\n", capitalize( ext_flag_string( &ch->subclasses, subclass_flags ) ) );
      send_to_char( "&B|------------------------&w[ &CFeats &w]&B-------------------------|\r\n", ch );
      ch_printf( ch, "  &C%s\r\n", capitalize( ext_flag_string( &ch->feats, feat_flags ) ) );
      send_to_char( "&B|-------------------&w[ &CActive Skills &w]&B---------------------|\r\n", ch );
      ch_printf( ch, "  &C%s\r\n", capitalize( ext_flag_string( &ch->abilities, ability_flags ) ) );
      send_to_char( "&B|---------------------&w[ &CAbilities &w]&B-----------------------|\r\n", ch );

   if( has_class( ch, CLASS_FIGHTER ) )
      show_fighter_abilities( ch );

   if( has_class( ch, CLASS_ROGUE ) )
      show_rogue_abilities( ch );

   if( has_class( ch, CLASS_WIZARD ) )
      show_wizard_abilities( ch );

   if( has_class( ch, CLASS_WARLOCK ) )
      show_warlock_abilities( ch );

   if( has_class( ch, CLASS_RANGER ) )
      show_ranger_abilities( ch );
      
/*      ch_printf( ch, "Points: %d\r\n", points );
      for( points = 0; points <= 2; points++ )
      {
         send_to_char( "Test\r\n", ch );
         points++;
      } */
      ch_printf( ch, "\r\n            &C::: &wCooldowns &C:::\r\n" );
      for( skill = ch->first_cooldown; skill; skill = skill->next )
      {
         ch_printf( ch, "  &C[&w%d&W/&w%d &cUses&C] &w%s\r\n", skill->curr_available, skill->max_available, skill_table[skill->sn]->name );
      }
      return;
   }
   return;
}

void do_levelup( CHAR_DATA *ch, const char *argument )
{
   MULTICLASS_DATA *multiclass;
   char arg[MAX_INPUT_LENGTH];
   bool found = false;
   int imc;
   int value = 0;

   one_argument( argument, arg );

   if( IS_NPC( ch ) )
   {
      send_to_char( "You can't multiclass!\r\n", ch );
      return;
   }

   if( arg[0] == '\0' )
   {
      ch_printf( ch, "Levelup which class?\r\n" );
      ch_printf( ch, "You have the following classes:\r\n" );
      for( multiclass = ch->first_multiclass; multiclass; multiclass = multiclass->next )
      {
         ch_printf( ch, "  &W%s&z: &C%d\r\n", capitalize( npc_class[multiclass->classname] ), multiclass->level );
      }
      return;
   }

/*   if( ch->exp < exp_level( ch, ch->level + 1 ) )
   {
      ch_printf( ch, "&RYou don't have enough experience to level yet, go forth and adventure!\r\n" );
      return;
   } */

   value = get_npc_class( argument );

   if( value < 0 || value >= MAX_CLASS )
   {
      ch_printf( ch, "%s is not a valid player class.\r\n", arg );
      return;
   }

   for( multiclass = ch->first_multiclass; multiclass; multiclass = multiclass->next )
   {
      if( multiclass->classname == value )
      {
         ch_printf( ch, "%s found! Advancing level from %d", npc_class[value], multiclass->level );
         multiclass->level++;
         ch_printf( ch, " to level %d.\r\n", multiclass->level );
         found = true;
         break;
      }
   }

   if( found != true )
   {
   
      CREATE( multiclass, MULTICLASS_DATA, 1 );
      multiclass->classname = value;
      multiclass->level = 1;
      LINK( multiclass, ch->first_multiclass, ch->last_multiclass, next, prev );
      ch_printf( ch, "%s not found! Adding to character classes.\r\n", npc_class[value] );
      save_char_obj( ch );
   }

   ++ch->level;
   advance_level( ch );
   log_printf( "%s has advanced to level %d!", ch->name, ch->level );

   if( has_class( ch, CLASS_FIGHTER ) ) 
   {
      switch( class_level( ch, CLASS_RANGER ) )
      {
         case 2:
            ch_printf( ch, "&WYou may now choose a favored enemy.\r\n" );
            break;

         case 4:
            ch_printf( ch, "&WYou may now choose a fighting style from the following options:\r\n " );
            ch_printf( ch, "&C1&c) &CArchery&w, &C2&c)&CDefense&w, &C3&c)&CDueling&w, &C4&c)&CTwo-Weapon\r\n" );
            ch_printf( ch, "Please make a selection (1-4):\r\n" );
            ch->desc->connected = CON_CHOOSE_WEAPONSTYLE_RANGER;
            break;
      }
      switch( class_level( ch, CLASS_FIGHTER ) )
      {
         case 2:
         case 20:
            ch_printf( ch, "&WYou may choose a fighting style from the following options:\r\n " );
            ch_printf( ch, "&C1&c) &CArchery&w, &C2&c)&CDefense&w, &C3&c)&CDueling&w,  &C4&c)&CTwo-Weapon, &C5&c)&CGreat Weapon&w, &C6&c)&CProtection&w,\r\n" );
            ch_printf( ch, "Please make a selection (1-6):\r\n" );
            ch->desc->connected = CON_CHOOSE_WEAPONSTYLE_FIGHTER;
            break;
         case 6:
            ch_printf( ch, "&WYou may now choose an archetype from Champion, Battle Master, or Eldritch Knight.\r\n" );
            break;
         case 8:
         case 12:
         case 16:
         case 24:
         case 28:
         case 32:
         case 38:
            ch_printf( ch, "&WYou may now select 2 attributes to raise.\r\n" );
            nanny_show_stats( ch->desc, argument );
            ch->tempnum = 2;
            ch->desc->connected = CON_RAISE_STAT;
            break;                  
         case 10:
            ch_printf( ch, "&WYou may now learn to make two attacks per turn.\r\n" );
            ch->pcdata->learned[gsn_second_attack] = 100;
            break;
         case 14:
            ch_printf( ch, "&WYou may now learn the &Gremarkable athlete &Wability, which allows you to add half your proficiency bonus to any Strength, Dexterity, or Constitution check.\r\n" );
            ch->pcdata->learned[gsn_remarkable_athlete] = 100;
            if( xIS_SET( ch->subclasses, SUBCLASS_BATTLEMASTER ) )
            {
               ch_printf( ch, "&WYou gain a combat superiority die!\r\n" );
               ch->classvalues[1]++;
               ch_printf( ch, "&WYou may also learn a new combat maneuver.\r\n" );
            }
            break;

         case 18:
            ch_printf( ch, "&WYou gain the &Gindomitable&W ability, which allows you to reroll a saving throw that you fail.\r\n" );
            ch->pcdata->learned[gsn_indomitable] = 100;
            break;

         case 22:
            ch_printf( ch, "&WYou gain the ability to make three attacks per turn.\r\n" );
            ch->pcdata->learned[gsn_third_attack] = 100;
            break;

         case 36:
            ch_printf( ch, "&WYou gain the &Gsurvivor&W ability, which regains &G%d &Whit points every turn.\r\n", con_app[get_curr_con( ch )].bonus+5 );
            ch->pcdata->learned[gsn_survivor] = 100;
            break;

         case 40:
            ch_printf( ch, "&WYou gain the ability to make four attacks per turn.\r\n" );
            ch->pcdata->learned[gsn_fourth_attack] = 100;
            break;
         
         default:
            ch_printf( ch, "&WYou've attained the next level! Congratulations!\r\n" );
            break;
      }
   }
/*
   if( has_class( ch, CLASS_WIZARD ) )
   {
      int x;
      for( x = 0; x < 9; x++ )
      {
         if( ch->max_slots[x] < full_cast_table[ch->level/2].max_casts[x] )
            ch->max_slots[x] = full_cast_table[ch->level/2].max_casts[x];
      }
   } */
   return;
}

void do_disengage( CHAR_DATA *ch, const char *argument )
{
   CHAR_DATA *victim;
   
   if( !who_fighting( ch ) )
   {
      if( ch->position == POS_FIGHTING
          || ch->position == POS_EVASIVE
          || ch->position == POS_DEFENSIVE || ch->position == POS_AGGRESSIVE || ch->position == POS_BERSERK )
      {
         if( ch->mount )
            ch->position = POS_MOUNTED;
         else
            ch->position = POS_STANDING;
      }
      send_to_char( "You aren't fighting anyone.\r\n", ch );
      return;
   }
   
   if( IS_AFFECTED( ch, AFF_BERSERK ) )
   {
      send_to_char( "Flee while berserking?  You aren't thinking very clearly...\r\n", ch );
      return;
   }

   if( IS_AFFECTED( ch, AFF_GRAPPLE ) )
   {
      send_to_char( "You're too wrapped up to flee!\r\n", ch );
      return;
   }

   if( ch->move <= 0 )
   {
      send_to_char( "You're too exhausted to flee from combat!\r\n", ch );
      return;
   }
   
   xSET_BIT( ch->affected_by, AFF_DISENGAGE );
   return;
}

/* Spits back a word for a stat being rolled or viewed in score - Samson 12-20-00 */
char *attribtext( int attribute )
{
   static char atext[MAX_STRING_LENGTH];
   atext[0] = '\0';

   if( attribute < 25 )
      mudstrlcpy( atext, "Excellent", MAX_STRING_LENGTH );
   if( attribute < 17 )
      mudstrlcpy( atext, "Good", MAX_STRING_LENGTH );
   if( attribute < 13 )
      mudstrlcpy( atext, "Fair", MAX_STRING_LENGTH );
   if( attribute < 9 )
      mudstrlcpy( atext, "Poor", MAX_STRING_LENGTH );
   if( attribute < 5 )
      mudstrlcpy( atext, "Bad", MAX_STRING_LENGTH );

   return atext;
}