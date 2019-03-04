#include <mudlib.h>
inherit MONSTER;
inherit MOUNT;
 
void create()
{
        ::create();
        set_level(16);
        set_name( "Red phoenix","[0;31m¡õ[1;31m¡õ[0;37m[0;31m¡õ[1;31m¡õ[0;37m[0;31m¡õ[1;31m¡õ[m"  );
        add( "id", ({ "phoenix" }) );
        set_short( "[0;31m¡õ[1;31m¡õ[0;37m[0;31m¡õ[1;31m¡õ[0;37m[0;31m¡õ[1;31m¡õ[m" );
        set_long(@C_LONG
Ò»Ö»ò§çïÑøµÄ³èÎï£¬È«Éí»ðÌ¿Ò²ËÆµÄ·ï»Ë£¬È«ÉíÓðÃ«ºÁÎÞ°ßÔÓ£¬¿¡ÃÀ¼«ÁË¡£ÕâÖ»»ð
·ï»ËÕýÔÚÌÞôáË¢Ã«£¬ÉñÇéÆÄÎª×ÔÔÚ¡£
C_LONG
        );        
        set( "unit", "Ö»" );
        set( "race", "monster");
        set( "race","·ïÄñ");
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
        set( "max_load", 2600 );
        set_c_limbs( ({ "·ï¹Ú", "ÉíÌå", "×¦", "Î²°Í","³á°ò" }) );
        set_c_verbs( ({ "%sÌ§Æð·ï×¦, Íù%sÒ»×¥", 
                        "%sÓÃËüµÄà¹×ÓÍù%sÒ»×Ä"}) );
}
void init()
{
    mount::init();
}
int stop_attack()
{
   object king;
   if ( king=present("ra-shan",environment()) ) {
      tell_room(environment(),"»ð·ï»ËÕÐ»½ËüµÄÖ÷ÈËÀ´¹¥»÷ËüµÄµÐÈË£¡\n\n");
      king->kill_ob(this_player());
   }
   return 0;
}
int do_mount(string arg)
{
   object king;
   
   if ( arg!="phoenix" ) return ::do_mount(arg);
   if ( this_player()->query_temp("mounting") ) return ::do_mount(arg);
   if ( king=present("ra-shan",environment()) ) {
     tell_room(environment(),sprintf("%sÅ­µÀ£ºÏëÍµÎÒµÄ·ï»Ë£¬ÃÅ¶¼Ã»ÓÐ£¬¿´À´ÎÒ²»ºÃºÃ½ÌÑµÄã£¬ÄãÊÇ²»ÖªµÀÍµÇÔÊÇ·¸·¨µÄ£¬¸øÎÒËÀËÀÈ¥£¡£¡\n"
      ,king->query("c_name")));
     king->kill_ob(this_player());
   }
   else ::do_mount(arg);
   return 1;
}
