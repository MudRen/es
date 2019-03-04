#include "/d/eastland/story/story.h"
#include <conditions.h>
inherit MONSTER ;
int cast=0;
int times=0;
int receive_damage(int damage);
void create ()
{
	::create();
	set_level(19);
	set_name( "King of the north Ra-Shan","ò§çï");
	add ("id", ({"king","ra-shan","Ra-Shan"}) );
	set_short( "±±·½ÌìµÛ ò§çï [ÆïÔÚÒ»Ö»[0;31m¡õ[1;31m¡õ[0;37m[0;31m¡õ[1;31m¡õ[0;37m[0;31m¡õ[1;31m¡õ[mÉÏ]");
	set_long(@CLONG
ò§çïÄËÊÇ»ÆµÛµÄÔøËï£¬¹ÜÀí±±·½»ýÑ©º®±ùµÄ»ÄÒ°£¬Ò»¹²Ò»Íò¶þÇ§ÀïµÄµØ·½¡£ò§çïÉú
µÃÏ¸Ã¼·ïÄ¿£¬ÄÚÌÃÉñÒÇ£¬·áÉñ¿¡ÀÊ£¬Ò»Éí°×Ò²ËÆµÄÑ©·ô£¬Á³ÉÏ²¢ÎÞÈÎºÎ±íÇé¡£ÉíÎª
ÉÏµÛµÄò§çï¶Ôì¶ÏÂ·½ÈËÃñµÄÍ´¿àËÆºõ²»Ôõ÷á¹ËÄî£¬µ«ËûÈ´½²¾¿¡¸Àñ·¨¡¹µÄ¡£
CLONG
	);
	set("race","god");
	set("gender","male");
	set_perm_stat("str", 24 );
        set_perm_stat("dex", 23 );
        set_perm_stat("kar", 28 );
        set_perm_stat("int", 28 );
	set( "alignment", 2000 );
	set( "hit_points", 1800 );
	set( "max_hp", 1800 );
        set( "max_fp",200);
	set_natural_weapon( 45, 8, 8 );
	set_natural_armor( 3, 26 );
        set_temp("detect_hide",1);
        set("aim_difficulty",([ 
    	  "critical":70,"vascular":40,"weakest":40 ]) );
        set("wealth/gold",300);
        set("stun_difficulty",100);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("dagger",100);
        set("tactic_func","my_tactic");
        wield_weapon(SPWEA"northgod_dagger");
        equip_armor(SPARM"northgod_cape");
        equip_armor(SPARM"northgod_cloth");
        equip_armor(SPARM"northgod_ring");
        equip_armor(SPARM"northgod_shield");
        set("special_defense",(["all":100,"none":45,"electric":10]));
}
int receive_damage(int damage)
{
  if ( damage>25 ) damage=25;
  ::receive_damage(damage);
}
int my_tactic()
{
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( cast ) {
      if ( times++ > 10 ) {
         tell_room(environment(),"½¥½¥µØ£¬ÂþÌìµÄ±ùÑ©ÈÜ»¯ì¶µØÉÏÄý½á³ÉË®µÎ£¡\n\n");      
         environment()->set("cast",0);
         cast=0;
         return 0;
      }
      return 0;
    }
    if ( random(10) > 1 ) return 0;
    tell_room(environment(),"\nò§ÏîË«ÊÖÍùÇ°Ì¯¿ª£¬¿ÕÆøÖÐÂúÊÇÂþÌì±ùÑ©£¡£¡\n\n");
    cast=1;
    times=0;
    environment()->set("cast",1);
    return 0;
}
void die()
{
   object phoenix;
   phoenix=new(SPMOB"phoenix");
   phoenix->move(environment());
   environment()->set("cast",0);
   set_short("±±·½ÌìµÛ ò§çï");
   ::die();
}
