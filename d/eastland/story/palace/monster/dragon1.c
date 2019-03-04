#include <mudlib.h>
inherit MONSTER;
inherit MOUNT;
 
void create()
{
        ::create();
        set_level(16);
        set_name( "Great dragon","[1;32m¡õ[1;36m¡õ[0;37m[1;32m¡õ[1;36ms[m");
        add( "id", ({ "dragon" }) );
        set_short( "[1;32m¡õ[1;36m¡õ[0;37m[1;32m¡õ[1;36ms[m");
        set_long(@C_LONG
Ò»Ö»ÐÔÇéÆÄÎªÎÂÑ±µÄ¶¯Îï£¬Ëü±ÈÆðÐí¶àÐ×¶ñµÄÓ¦ÁúÖÐÎÂÉÆÐí¶àÁË¡£ËüÊÇ»ÆµÛ×îÐÄ°®
µÄ³èÎï£¬ÏÖÔÚÕý·üÎÔÔÚµØÉÏ£¬ÆÄÎªÓÆÏÐ×ÔÔÚ¡£
C_LONG
        );        
        set( "unit", "Ö»" );
        set( "race", "Áú×å");
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "int", 15 );
        set_perm_stat( "con", 25 );
        set_perm_stat( "kar", 25 );
        set_natural_weapon( 45,33,53 );
        set_natural_armor( 76,39 );
        set_skill("dodge",60);
        set( "alignment", 0 );
        set( "mountable", 1);
        set( "max_load",3000 );
        set_c_limbs(({"ÉíÌå","Í·²¿","Ç°×¦","áá×¦"}));
        set_c_verbs(({
            "%sÓÃËüµÄÀû×¦Ïò%s×¥È¥",
            "%sÉì³öËüÄÇ³¤ÂúÀûÑÀµÄ×ì°ÍÏò%sÒ§È¥"
        }));
}
void init()
{
    mount::init();
}
int stop_attack()
{
   object king;
   if ( king=present("the king huang",environment()) ) {
      tell_room(environment(),"Ó¦ÁúÕÐ»½ËüµÄÖ÷ÈËÀ´¹¥»÷ËüµÄµÐÈË£¡\n\n");
      king->kill_ob(this_player());
   }
   return 0;
}
int do_mount(string arg)
{
   object king;
   
   if ( arg!="dragon" ) return ::do_mount(arg);
   if ( this_player()->query_temp("mounting") ) return ::do_mount(arg);
   if ( king=present("the king huang",environment()) ) {
     tell_room(environment(),sprintf("%sËµµÀ£ºÏëÆï°¡£¬ÏÈ´ò°ÜÎÒÔÙËµ£¡£¡\n"
      ,king->query("c_name")));
     king->kill_ob(this_player());
   }
   else ::do_mount(arg);
   return 1;
}
