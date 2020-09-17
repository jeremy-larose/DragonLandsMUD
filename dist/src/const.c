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
 *                           Mud constants module                           *
 ****************************************************************************/

#include <stdio.h>
#include "mud.h"

const char *const npc_race[MAX_NPC_RACE] = {
   // Playable races - MAX_RACE in mud.h must be raised before more can be added after r9.
   "human", "avariel", "hill-dwarf", "mountain-dwarf", "high-elf", "wood-elf", "dark-elf",       // 6 (start from 0)
   "lightfoot-halfing", "stout-halfling", "dragonborn", "forest-gnome", "rock-gnome", "half-elf",            // 12
   "half-orc", "tiefling", "aasimar", "lizardman", "feyborn", "r8", "r9",                         // 19

   // NPCs only
   "troll", "ant", "ape", "baboon", "bat", "bear", "bee",                      // 26
   "beetle", "boar", "bugbear", "cat", "dog", "dragon", "ferret", "fly",       // 34
   "gargoyle", "gelatin", "ghoul", "gnoll", "goblin", "golem",                 // 40
   "gorgon", "harpy", "hobgoblin", "kobold", "locust",                         // 45
   "lycanthrope", "minotaur", "mold", "mule", "neanderthal", "ooze", "orc",    // 52
   "rat", "rustmonster", "shadow", "shapeshifter", "shrew", "shrieker",        // 58
   "skeleton", "slime", "snake", "spider", "stirge", "thoul", "troglodyte",    // 65
   "undead", "wight", "wolf", "worm", "zombie", "bovine", "canine", "feline",  // 73
   "porcine", "mammal", "rodent", "avis", "reptile", "amphibian", "fish",      // 80
   "crustacean", "insect", "spirit", "magical", "horse", "animal", "humanoid", // 87
   "monster", "god", "???"                                                     // 90
};

const char *const npc_type[MAX_NPC_TYPE] = {
   "humanoid", "beast", "celestial", "construct", "dragon", "elemental",
   "fey", "fiend", "giant", "aberration", "monster", "ooze", "plant", "undead", "???"
};

const char *const npc_class[MAX_NPC_CLASS] = {
   "wizard", "cleric", "rogue", "fighter", "paladin", "ranger", "barbarian",
   "druid", "bard", "monk", "sorcerer", "warlock", "baker", "butcher", "blacksmith",
   "mayor", "king", "queen"
};

const char *const background_types[] = {
   "none", "acolyte", "charlatan", "criminal", "entertainer", "folkhero", "artisan",
   "merchant", "hermit", "noble", "outlander", "sage", "sailor", "pirate",
   "soldier", "urchin"
};

/*
 * Attribute bonus tables.
 */
const struct str_app_type str_app[31] = {
   {-5, -5, 0, 0},   /* 0  */
   {-5, -5, 15, 1},   /* 1  */
   {-4, -4, 30, 2},
   {-4, -4, 45, 3},  /* 3  */
   {-3, -3, 60, 4},
   {-3, -3, 75, 5},  /* 5  */
   {-2, -2, 90, 6},
   {-2, -2, 105, 7},
   {-1, -1, 120, 8},
   {-1, -1, 135, 9},
   {0, 0, 150, 10},  /* 10  */
   {0, 0, 165, 11},
   {1, 1, 180, 12},
   {1, 1, 195, 13},  /* 13  */
   {2, 2, 210, 14},
   {2, 2, 225, 15},  /* 15  */
   {3, 3, 240, 16},
   {3, 3, 265, 22},
   {4, 4, 280, 25},  /* 18  */
   {4, 4, 295, 30},
   {5, 5, 310, 35},  /* 20  */
   {5, 5, 325, 40},
   {6, 6, 340, 45},
   {6, 6, 365, 50},
   {7, 7, 380, 55},
   {7, 7, 395, 60}, /* 25 */
   {8, 8, 410, 60},
   {8, 8, 425, 60},
   {9, 9, 440, 60},
   {9, 9, 455, 60},
   {10, 10, 470, 60} /* 30 */
};

const struct int_app_type int_app[31] = {
   {-5},  /*  0 */
   {-5},  /*  1 */
   {-4},
   {-4},  /*  3 */
   {-3},
   {-3}, /*  5 */
   {-2},
   {-2},
   {-1},
   {-1},
   {0}, /* 10 */
   {0},
   {1},
   {1},
   {2},
   {2}, /* 15 */
   {3},
   {3},
   {4}, /* 18 */
   {4},
   {5}, /* 20 */
   {5},
   {6},
   {6},
   {7},
   {7},  /* 25 */
   {8},
   {8},
   {9},
   {9},
   {10} /* 30 */
};

const struct wis_app_type wis_app[31] = {
   {-5},  /*  0 */
   {-5},  /*  1 */
   {-4},
   {-4},  /*  3 */
   {-3},
   {-3}, /*  5 */
   {-2},
   {-2},
   {-1},
   {-1},
   {0}, /* 10 */
   {0},
   {1},
   {1},
   {2},
   {2}, /* 15 */
   {3},
   {3},
   {4}, /* 18 */
   {4},
   {5}, /* 20 */
   {5},
   {6},
   {6},
   {7},
   {7},  /* 25 */
   {8},
   {8},
   {9},
   {9},
   {10} /* 30 */
};

const struct dex_app_type dex_app[31] = {
   {-5},  /*  0 */
   {-5},  /*  1 */
   {-4},
   {-4},  /*  3 */
   {-3},
   {-3}, /*  5 */
   {-2},
   {-2},
   {-1},
   {-1},
   {0}, /* 10 */
   {0},
   {1},
   {1},
   {2},
   {2}, /* 15 */
   {3},
   {3},
   {4}, /* 18 */
   {4},
   {5}, /* 20 */
   {5},
   {6},
   {6},
   {7},
   {7},  /* 25 */
   {8},
   {8},
   {9},
   {9},
   {10} /* 30 */
};

const struct con_app_type con_app[31] = {
   {-5, 20},   /*  0 */
   {-5, 25},   /*  1 */
   {-4, 30},
   {-4, 35},   /*  3 */
   {-3, 40},
   {-3, 45},   /*  5 */
   {-2, 50},
   {-2, 55},
   {-1, 60},
   {-1, 65},
   {0, 70}, /* 10 */
   {0, 75},
   {1, 80},
   {1, 85},
   {2, 88},
   {2, 90}, /* 15 */
   {3, 95},
   {3, 97},
   {4, 99}, /* 18 */
   {4, 99},
   {5, 99}, /* 20 */
   {5, 99},
   {6, 99},
   {6, 99},
   {7, 99},
   {7, 99},  /* 25 */
   {8, 99},
   {8, 99},
   {9, 99},
   {9, 99},
   {10, 99}, /* 30 */
};

const struct cha_app_type cha_app[31] = {
   {-5},  /*  0 */
   {-5},  /*  1 */
   {-4},
   {-4},  /*  3 */
   {-3},
   {-3}, /*  5 */
   {-2},
   {-2},
   {-1},
   {-1},
   {0}, /* 10 */
   {0},
   {1},
   {1},
   {2},
   {2}, /* 15 */
   {3},
   {3},
   {4}, /* 18 */
   {4},
   {5}, /* 20 */
   {5},
   {6},
   {6},
   {7},
   {7},  /* 25 */
   {8},
   {8},
   {9},
   {9},
   {10} /* 30 */
};

/* Have to fix this up - not exactly sure how it works (Scryn) */
const struct lck_app_type lck_app[31] = {
   {-5},  /*  0 */
   {-5},  /*  1 */
   {-4},
   {-4},  /*  3 */
   {-3},
   {-3}, /*  5 */
   {-2},
   {-2},
   {-1},
   {-1},
   {0}, /* 10 */
   {0},
   {1},
   {1},
   {2},
   {2}, /* 15 */
   {3},
   {3},
   {4}, /* 18 */
   {4},
   {5}, /* 20 */
   {5},
   {6},
   {6},
   {7},
   {7},  /* 25 */
   {8},
   {8},
   {9},
   {9},
   {10} /* 30 */
};

const struct   mob_challenge_type       challenge_table [34] =
{
   {0, 2, 10},
   {1, 2, 25},
   {2, 2, 50},
   {3, 2, 100},
   {4, 2, 200},
   {5, 2, 450},
   {6, 2, 700},
   {7, 2, 1100},
   {8, 3, 1800},
   {9, 3, 2300},
   {10, 3, 2900},
   {11, 3, 3900},
   {12, 4, 5000},
   {13, 4, 5900},
   {14, 4, 7200},
   {15, 4, 8400},
   {16, 5, 10000},
   {17, 5, 11500},
   {18, 5, 13000},
   {19, 5, 15000},
   {20, 6, 18000},
   {21, 6, 20000},
   {22, 6, 22000},
   {23, 6, 25000},
   {24, 7, 33000},
   {25, 7, 41000},
   {26, 7, 50000},
   {27, 7, 62000},
   {28, 8, 75000},
   {29, 8, 90000},
   {30, 8, 105000},
   {31, 8, 120000},
   {32, 9, 135000},
   {33, 9, 155000}
};
/*
 * These are the spell progression tables for different classes
 * Seikyr (Jeremy LaRose) 1/17
 * 
 */
const   struct  half_cast_type   half_cast_table [] =
{
   { 1, {0, 0, 0, 0, 0, 0, 0, 0, 0 }},
   { 4, {2, 0, 0, 0, 0, 0, 0, 0, 0 }},
   { 6, {3, 0, 0, 0, 0, 0, 0, 0, 0 }},
   { 8, {3, 0, 0, 0, 0, 0, 0, 0, 0 }},
   { 10, {4, 2, 0, 0, 0, 0, 0, 0, 0 }},
   { 12, {4, 2, 0, 0, 0, 0, 0, 0, 0 }},
   { 14, {4, 3, 0, 0, 0, 0, 0, 0, 0 }},
   { 16, {4, 3, 0, 0, 0, 0, 0, 0, 0 }},
   { 18, {4, 3, 2, 0, 0, 0, 0, 0, 0 }},
   { 20, {4, 3, 2, 0, 0, 0, 0, 0, 0 }},
   { 22, {4, 3, 3, 0, 0, 0, 0, 0, 0 }},
   { 24, {4, 3, 3, 0, 0, 0, 0, 0, 0 }},
   { 26, {4, 3, 3, 1, 0, 0, 0, 0, 0 }},
   { 28, {4, 3, 3, 1, 0, 0, 0, 0, 0 }},
   { 30, {4, 3, 3, 2, 0, 0, 0, 0, 0 }},
   { 32, {4, 3, 3, 2, 0, 0, 0, 0, 0 }},
   { 34, {4, 3, 3, 3, 1, 0, 0, 0, 0 }},
   { 36, {4, 3, 3, 3, 1, 0, 0, 0, 0 }},
   { 38, {4, 3, 3, 3, 2, 0, 0, 0, 0 }},
   { 40, {4, 3, 3, 3, 2, 0, 0, 0, 0 }},
   { 42, {5, 4, 3, 3, 3, 1, 0, 0, 0 }},
   { 44, {5, 4, 3, 3, 3, 1, 0, 0, 0 }},
   { 46, {5, 4, 3, 3, 3, 2, 0, 0, 0 }},
   { 48, {5, 4, 4, 3, 3, 2, 0, 0, 0 }},
   { 50, {5, 5, 4, 4, 3, 3, 1, 0, 0 }},
   { (MAX_LEVEL + 1),{0,0,0,0,0,0,0,0,0 }}
};
const    struct   third_cast_type   third_cast_table [] =
{
   { 1, {0, 0, 0, 0, 0, 0, 0, 0, 0 }},
   { 4, {0, 0, 0, 0, 0, 0, 0, 0, 0 }},
   { 6, {2, 0, 0, 0, 0, 0, 0, 0, 0 }},
   { 8, {3, 0, 0, 0, 0, 0, 0, 0, 0 }},
   {10, {3, 0, 0, 0, 0, 0, 0, 0, 0 }},
   {12, {3, 0, 0, 0, 0, 0, 0, 0, 0 }},
   {14, {4, 2, 0, 0, 0, 0, 0, 0, 0 }},
   {16, {4, 2, 0, 0, 0, 0, 0, 0, 0 }},
   {18, {4, 2, 0, 0, 0, 0, 0, 0, 0 }},
   {20, {4, 3, 0, 0, 0, 0, 0, 0, 0 }},
   {22, {4, 3, 0, 0, 0, 0, 0, 0, 0 }},
   {24, {4, 3, 0, 0, 0, 0, 0, 0, 0 }},
   {26, {4, 3, 2, 0, 0, 0, 0, 0, 0 }},
   {28, {4, 3, 2, 0, 0, 0, 0, 0, 0 }},
   {30, {4, 3, 2, 0, 0, 0, 0, 0, 0 }},
   {32, {4, 3, 3, 0, 0, 0, 0, 0, 0 }},
   {34, {4, 3, 3, 0, 0, 0, 0, 0, 0 }},
   {36, {4, 3, 3, 0, 0, 0, 0, 0, 0 }},
   {38, {4, 3, 3, 1, 0, 0, 0, 0, 0 }},
   {40, {4, 3, 3, 1, 0, 0, 0, 0, 0 }},
   {42, {5, 4, 3, 2, 0, 0, 0, 0, 0 }},
   {44, {5, 4, 3, 2, 0, 0, 0, 0, 0 }},
   {46, {5, 4, 3, 3, 0, 0, 0, 0, 0 }},
   {48, {5, 4, 4, 3, 0, 0, 0, 0, 0 }},
   {50, {5, 5, 4, 3, 1, 0, 0, 0, 0 }},
   {(MAX_LEVEL + 1),{0,0,0,0,0,0,0,0,0 }}
};
const   struct  full_cast_type  full_cast_table []  =
{
   { 1, {2, 0, 0, 0, 0, 0, 0, 0, 0 }},
   { 4, {3, 0, 0, 0, 0, 0, 0, 0, 0 }},
   { 6, {4, 2, 0, 0, 0, 0, 0, 0, 0 }},
   { 8, {4, 3, 0, 0, 0, 0, 0, 0, 0 }},
   {10, {4, 3, 2, 0, 0, 0, 0, 0, 0 }},
   {12, {4, 3, 3, 0, 0, 0, 0, 0, 0 }},
   {14, {4, 3, 3, 1, 0, 0, 0, 0, 0 }},
   {16, {4, 3, 3, 2, 0, 0, 0, 0, 0 }},
   {18, {4, 3, 3, 3, 1, 0, 0, 0, 0 }},
   {20, {4, 3, 3, 3, 2, 0, 0, 0, 0 }},
   {22, {4, 3, 3, 3, 2, 1, 0, 0, 0 }},
   {24, {4, 3, 3, 3, 2, 1, 0, 0, 0 }},
   {26, {4, 3, 3, 3, 2, 1, 1, 0, 0 }},
   {28, {4, 3, 3, 3, 2, 1, 1, 0, 0 }},
   {30, {4, 3, 3, 3, 2, 1, 1, 1, 0 }},
   {32, {4, 3, 3, 3, 2, 1, 1, 1, 0 }},
   {34, {4, 3, 3, 3, 2, 1, 1, 1, 1 }},
   {36, {4, 3, 3, 3, 3, 1, 1, 1, 1 }},
   {38, {4, 3, 3, 3, 3, 2, 1, 1, 1 }},
   {40, {4, 3, 3, 3, 3, 2, 2, 1, 1 }},
   {42, {5, 4, 3, 3, 3, 2, 2, 1, 1 }},
   {44, {5, 4, 3, 3, 3, 2, 2, 1, 1 }},
   {46, {5, 4, 4, 3, 3, 2, 2, 2, 1 }},
   {48, {5, 4, 4, 4, 3, 3, 2, 2, 1 }},
   {50, {5, 5, 4, 4, 4, 3, 3, 3, 2 }},
   {(MAX_LEVEL + 1),{0,0,0,0,0,0,0,0,0 }}
};

const   struct  max_mem_type  max_mem_table []  =
{
  {1,  {2, 2, 0, 0, 0, 0, 0, 0, 0, 0}},
  {4,  {2, 2, 0, 0, 0, 0, 0, 0, 0, 0}},
  {6,  {3, 3, 3, 0, 0, 0, 0, 0, 0, 0}},
  {8,  {4, 4, 4, 0, 0, 0, 0, 0, 0, 0}},
  {10, {5, 5, 5, 5, 0, 0, 0, 0, 0, 0}},
  {12, {6, 6, 6, 6, 0, 0, 0, 0, 0, 0}},
  {14, {7, 7, 7, 7, 7, 0, 0, 0, 0, 0}},
  {16, {8, 8, 8, 8, 8, 0, 0, 0, 0, 0}},
  {18, {4, 4, 3, 3, 3, 1, 0, 0, 0, 0}},
  {20, {5, 4, 3, 3, 3, 2, 0, 0, 0, 0}},
  {22, {5, 4, 3, 3, 3, 2, 1, 0, 0, 0}},
  {24, {5, 4, 3, 3, 3, 2, 1, 0, 0, 0}},
  {26, {5, 4, 3, 3, 3, 2, 1, 1, 0, 0}},
  {28, {5, 4, 3, 3, 3, 2, 1, 1, 1, 0}},
  {30, {5, 4, 3, 3, 3, 2, 1, 1, 1, 0}},
  {32, {5, 4, 3, 3, 3, 2, 1, 1, 1, 0}},
  {34, {5, 4, 3, 3, 3, 3, 1, 1, 1, 1}},
  {36, {5, 4, 3, 3, 3, 3, 1, 1, 1, 1}},
  {38, {5, 4, 3, 3, 3, 3, 2, 1, 1, 1}},
  {40, {5, 4, 3, 3, 3, 3, 2, 2, 1, 1}},
  {42, {5, 5, 4, 3, 3, 3, 2, 2, 1, 1}},
  {44, {5, 5, 4, 3, 3, 3, 3, 2, 1, 1}},
  {46, {5, 5, 4, 3, 3, 3, 3, 3, 2, 1}},
  {48, {5, 5, 4, 4, 3, 3, 3, 3, 2, 1}},
  {50, {5, 5, 5, 4, 4, 3, 3, 3, 3, 2}},
  {(MAX_LEVEL + 1), {0,0,0,0,0,0,0,0,0,0,0}}
};

const   struct  circle_wait_type  circle_wait_table []  =
{
  {1,  1},
  {2,  2},
  {3,  2},
  {4,  2},
  {5,  3},
  {6,  3},
  {7,  4},
  {8,  4},
  {9,  5},
  {10, 5},
  {11, 6},
  {12, 6},
  {13, 7},
  {14, 7},
  {15, 8},
  {16, 9},
  {0, 0}     /* included for a stopping point for possible future searches */
};

const struct   level_prog_type  level_prog_table [66] =
{
   {2, 0},       {2, 300},     {2, 900},  /* 3 */
   {2, 2700},    {2, 6500},    {2, 14000}, /* 6 */
   {2, 23000},   {2, 34000},   {2, 48000}, /* 9 */
   {3, 64000},   {3, 85000},   {3, 100000}, /* 12 */
   {3, 120000},  {3, 140000},  {3, 165000}, /* 15 */
   {3, 195000},  {3, 225000},  {3, 265000}, /* 18 */
   {3, 305000},  {3, 355000},  {4, 405000}, /* 21 */
   {4, 460000},  {4, 525000},  {4, 585000}, /* 24 */
   {5, 655000},  {5, 725000},  {5, 805000}, /* 27 */
   {5, 885000},  {5, 975000},  {5, 1045000}, /* 30 */
   {5, 1135000}, {5, 1225000}, {6, 1325000}, /* 33 */
   {6, 1425000}, {6, 1535000}, {6, 1645000}, /* 36 */
   {6, 1765000}, {6, 1885000}, {6, 2015000}, /* 39 */
   {6, 2145000}, {7, 2275000}, {7, 2415000}, /* 42 */
   {7, 2555000}, {7, 2705000}, {7, 2855000}, /* 45 */
   {7, 3015000}, {7, 3175000}, {7, 3350000}, /* 48 */
   {7, 3525000}, {8, 3725000}, {8, 3925000}, /* 51 */
   {8, 4125000}, {8, 4325000}, {8, 4525000}, /* 54 */
   {8, 4725000}, {8, 4975000}, {8, 5225000}, /* 57 */
   {8, 5475000}, {9, 5725000}, {9, 5975000}, /* 60 */
   {9, 6225000}, {9, 6475000}, {9, 6725000}, /* 63 */
   {9, 6975000}, {10,8000000}, {10,8000000}  /* 65 */
};

/*
 * 5th Edition D&D Armor Tables
 * { A, B, C, D, E }
 * A [0]= Base Armor Class
 * B [1]= Maximum Dexterity Modifier
 * C [2]= Armor Type (0 = Naked, 1 = Cloth, 2 = Light, 3 = Medium, 4 = Heavy)
 * D [3]= Disadvantage to Stealth (0 = False, 1 = True)
 * E [4]= Min Str Required
 *
 * Seikyr 1/17
 */
const struct   base_armor_type  armor_table[MAX_ARMOR_TYPE] =
{
   { 0, 10, 0, 0, 0 }, /* Naked */
   { 0, 10, 1, 0, 0 }, /* Cloth */
   { 10, 10, 2, 1, 0 }, /* Padded */
   { 10, 10, 2, 0, 0 }, /* Leather */
   { 12, 10, 2, 0, 0 }, /* Studded Leather */
   { 12,  2, 3, 0, 0 }, /* Hide */
   { 13,  2, 3, 0, 0 }, /* Chain Shirt */
   { 13, 10, 1, 0, 0 }, /* Mage Armor */
   { 13, 10, 1, 0, 0 }, /* Draconic Resilience */
   { 14,  2, 3, 1, 0 }, /* Scale Mail */
   { 14,  2, 3, 0, 0 }, /* Breast Plate */
   { 15,  2, 3, 1, 0 }, /* Half Plate */
   { 14,  0, 4, 1, 0 }, /* Ring Mail */
   { 16,  0, 4, 1, 13}, /* Chain Mail */
   { 17,  0, 4, 1, 15}, /* Splint Mail */
   { 18,  0, 4, 1, 15}, /* Plate Mail */
};

/* removed "pea" and added chop, spear, smash - Grimm */
/* Removed duplication in damage types - Samson 1-9-00 */
const char * attack_table[DAM_MAX_TYPE] =
{
   "hit", "slash", "crush", "pierce"
};

const char * attack_table_plural[DAM_MAX_TYPE] =
{
   "hits", "slashes", "crushes", "pierces"
};

const char * weapon_skills[WEP_MAX] =
{
  "barehand", "long sword", "short sword", "rapier", "scimitar", "dagger",
  "whip", "talon", "mace", "bow", "crossbow", "blowgun", "sling", "axe", "spear", "staff",
  "javelin", "halberd", "sickle", "club", "lance", "hammer", "net", "dart"
};

const char * projectiles[PROJ_MAX] =
{
   "bolt", "arrow", "dart", "stone"
};

const char *s_blade_messages[24] = {
   "miss", "barely scratch", "scratch", "nick", "cut", "hit", "tear",
   "rip", "gash", "lacerate", "hack", "maul", "rend", "decimate",
   "_mangle_", "_devastate_", "_cleave_", "_butcher_", "DISEMBOWEL",
   "DISFIGURE", "GUT", "EVISCERATE", "* SLAUGHTER *", "*** ANNIHILATE ***"
};

const char *p_blade_messages[24] = {
   "misses", "barely scratches", "scratches", "nicks", "cuts", "hits",
   "tears", "rips", "gashes", "lacerates", "hacks", "mauls", "rends",
   "decimates", "_mangles_", "_devastates_", "_cleaves_", "_butchers_",
   "DISEMBOWELS", "DISFIGURES", "GUTS", "EVISCERATES", "* SLAUGHTERS *",
   "*** ANNIHILATES ***"
};

const char *s_blunt_messages[24] = {
   "miss", "barely scuff", "scuff", "pelt", "bruise", "strike", "thrash",
   "batter", "flog", "pummel", "smash", "maul", "bludgeon", "decimate",
   "_shatter_", "_devastate_", "_maim_", "_cripple_", "MUTILATE", "DISFIGURE",
   "MASSACRE", "PULVERIZE", "* OBLITERATE *", "*** ANNIHILATE ***"
};

const char *p_blunt_messages[24] = {
   "misses", "barely scuffs", "scuffs", "pelts", "bruises", "strikes",
   "thrashes", "batters", "flogs", "pummels", "smashes", "mauls",
   "bludgeons", "decimates", "_shatters_", "_devastates_", "_maims_",
   "_cripples_", "MUTILATES", "DISFIGURES", "MASSACRES", "PULVERIZES",
   "* OBLITERATES *", "*** ANNIHILATES ***"
};

const char *s_generic_messages[24] = {
   "miss", "brush", "scratch", "graze", "nick", "jolt", "wound",
   "injure", "hit", "jar", "thrash", "maul", "decimate", "_traumatize_",
   "_devastate_", "_maim_", "_demolish_", "MUTILATE", "MASSACRE",
   "PULVERIZE", "DESTROY", "* OBLITERATE *", "*** ANNIHILATE ***",
   "**** SMITE ****"
};

const char *p_generic_messages[24] = {
   "misses", "brushes", "scratches", "grazes", "nicks", "jolts", "wounds",
   "injures", "hits", "jars", "thrashes", "mauls", "decimates", "_traumatizes_",
   "_devastates_", "_maims_", "_demolishes_", "MUTILATES", "MASSACRES",
   "PULVERIZES", "DESTROYS", "* OBLITERATES *", "*** ANNIHILATES ***",
   "**** SMITES ****"
};

const char ** const s_message_table[DAM_MAX_TYPE] =
{
   s_generic_messages,     /* hit */
   s_blade_messages,       /* slash */
   s_blunt_messages,       /* crush */
   s_blade_messages,       /* pierce */
};

const char ** const p_message_table[DAM_MAX_TYPE] =
{
   p_generic_messages,     /* hit */
   p_blade_messages,       /* slash */
   p_blunt_messages,       /* crush */
   p_blade_messages,       /* pierce */
};

/* Weather constants - FB */
const char *const temp_settings[MAX_CLIMATE] = {
   "cold",
   "cool",
   "normal",
   "warm",
   "hot",
};

const char *const precip_settings[MAX_CLIMATE] = {
   "arid",
   "dry",
   "normal",
   "damp",
   "wet",
};

const char *const wind_settings[MAX_CLIMATE] = {
   "still",
   "calm",
   "normal",
   "breezy",
   "windy",
};

const char *const preciptemp_msg[6][6] = {
   /*
    * precip = 0 
    */
   {
    "Frigid temperatures settle over the land",
    "It is bitterly cold",
    "The weather is crisp and dry",
    "A comfortable warmth sets in",
    "A dry heat warms the land",
    "Seething heat bakes the land"},
   /*
    * precip = 1 
    */
   {
    "A few flurries drift from the high clouds",
    "Frozen drops of rain fall from the sky",
    "An occasional raindrop falls to the ground",
    "Mild drops of rain seep from the clouds",
    "It is very warm, and the sky is overcast",
    "High humidity intensifies the seering heat"},
   /*
    * precip = 2 
    */
   {
    "A brief snow squall dusts the earth",
    "A light flurry dusts the ground",
    "Light snow drifts down from the heavens",
    "A light drizzle mars an otherwise perfect day",
    "A few drops of rain fall to the warm ground",
    "A light rain falls through the sweltering sky"},
   /*
    * precip = 3 
    */
   {
    "Snowfall covers the frigid earth",
    "Light snow falls to the ground",
    "A brief shower moistens the crisp air",
    "A pleasant rain falls from the heavens",
    "The warm air is heavy with rain",
    "A refreshing shower eases the oppresive heat"},
   /*
    * precip = 4 
    */
   {
    "Sleet falls in sheets through the frosty air",
    "Snow falls quickly, piling upon the cold earth",
    "Rain pelts the ground on this crisp day",
    "Rain drums the ground rythmically",
    "A warm rain drums the ground loudly",
    "Tropical rain showers pelt the seering ground"},
   /*
    * precip = 5 
    */
   {
    "A downpour of frozen rain covers the land in ice",
    "A blizzard blankets everything in pristine white",
    "Torrents of rain fall from a cool sky",
    "A drenching downpour obscures the temperate day",
    "Warm rain pours from the sky",
    "A torrent of rain soaks the heated earth"}
};

const char *const windtemp_msg[6][6] = {
   /*
    * wind = 0 
    */
   {
    "The frigid air is completely still",
    "A cold temperature hangs over the area",
    "The crisp air is eerily calm",
    "The warm air is still",
    "No wind makes the day uncomfortably warm",
    "The stagnant heat is sweltering"},
   /*
    * wind = 1 
    */
   {
    "A light breeze makes the frigid air seem colder",
    "A stirring of the air intensifies the cold",
    "A touch of wind makes the day cool",
    "It is a temperate day, with a slight breeze",
    "It is very warm, the air stirs slightly",
    "A faint breeze stirs the feverish air"},
   /*
    * wind = 2 
    */
   {
    "A breeze gives the frigid air bite",
    "A breeze swirls the cold air",
    "A lively breeze cools the area",
    "It is a temperate day, with a pleasant breeze",
    "Very warm breezes buffet the area",
    "A breeze ciculates the sweltering air"},
   /*
    * wind = 3 
    */
   {
    "Stiff gusts add cold to the frigid air",
    "The cold air is agitated by gusts of wind",
    "Wind blows in from the north, cooling the area",
    "Gusty winds mix the temperate air",
    "Brief gusts of wind punctuate the warm day",
    "Wind attempts to cut the sweltering heat"},
   /*
    * wind = 4 
    */
   {
    "The frigid air whirls in gusts of wind",
    "A strong, cold wind blows in from the north",
    "Strong wind makes the cool air nip",
    "It is a pleasant day, with gusty winds",
    "Warm, gusty winds move through the area",
    "Blustering winds punctuate the seering heat"},
   /*
    * wind = 5 
    */
   {
    "A frigid gale sets bones shivering",
    "Howling gusts of wind cut the cold air",
    "An angry wind whips the air into a frenzy",
    "Fierce winds tear through the tepid air",
    "Gale-like winds whip up the warm air",
    "Monsoon winds tear the feverish air"}
};

const char *const precip_msg[3] = {
   "there is not a cloud in the sky",
   "pristine white clouds are in the sky",
   "thick, grey clouds mask the sun"
};

const char *const wind_msg[6] = {
   "there is not a breath of wind in the air",
   "a slight breeze stirs the air",
   "a breeze wafts through the area",
   "brief gusts of wind punctuate the air",
   "angry gusts of wind blow",
   "howling winds whip the air into a frenzy"
};
