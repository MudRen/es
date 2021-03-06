#include "mercury.h"
inherit MMOB+"magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Master Nei", "雷帝 亚协斯.妮" );
	add( "id", ({ "master","nei" }) );
	set_short( "Master Nei", "雷帝 亚协斯.妮" );
	set_long(@AAA
在你眼前是一位相当动人的女子，美丽的脸蛋配上诱人的身材，让人
想不道她居然也是武士团忍者部队的首领之一，她和葛拉并称为忍者
军团的两大天王，而由於妮擅长使用雷系魔法，故又称之为雷帝！！　	
AAA
 );
	set( "unit", "位" );
	set( "race", "human" );
	set( "gender", "female" );
	set_perm_stat( "str", 27 );
	set_perm_stat( "int", 30 );
        set_perm_stat( "dex", 30 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "pie", 30 );    
        set( "max_hp",950 );
        set( "hit_points",950 );
 	set_natural_armor( 55,35 );
	set( "natural_weapon_class1", 25 );
	set( "natural_min_damage1", 20 );
	set( "natural_max_damage1", 40 ); 
        set( "special_defense",([ "all":45,"none":35 ])); 
        set( "aim_difficulty",([ "critical":100,"weakest":30,"ganglion":60,
                                 "vascular":30 ]));
        set( "stun_difficulty/ma",5);  
	set( "alignment", 1500 );
	set_c_limbs( ({ "头部", "身体", "手腕", "咽喉" }) );
        set_skill( "parry",100 );
        set_skill( "longblade",100 );
        set_skill( "block",100);
        set_skill( "tactic",100);
        set_skill( "dodge",100);
        set("tactic","berserk");
        set( "wealth" , ([ "gold": 70 ]) );
        set( "tactic_func", "att_gonfus");
        wield_weapon(MOBJ"sword2");
        equip_armor(MOBJ"nei_cloak");
        equip_armor(MOBJ"nei_vest");
        equip_armor(MOBJ"nei_shield");
}

int att_gonfus()
{
     object victim;
     int dam,n;
     if( !(victim = query_attacker()) || (random(25)>4) ) return 0;
 else{    switch(n=random(2))
 { case 0:    
 {    
     tell_room(environment(this_object()), 
     "\n妮大喝一声:看我的霸皇剑奥义 雷击鹫爪斩\n"+
     "\n妮的手上的剑散发出一股股雷电，以迅雷之速斩向"+victim->query("c_name")+"\n\n"
       );
      dam = 25 + random(35);
      victim->receive_special_damage("eletric", dam );
      report(this_object(),victim);
      return 1;     
}
 case 1:
{      tell_room(environment(this_object()),
       "\n妮高声吟唱咒文:遵循著神灵之血与祭坛上与神所定之契约\n"+
       "\n妮高声吟唱咒文:以我之名，雷之精灵听我号令，　落雷　！！\n\n"
       );
       call_out("to_attack",4);
       return 1;
}
}
}      
}
int to_attack()
{   object victim;
    int dam;
    victim = query_attacker();
    if (!victim) return 1;
      tell_room(environment(this_player()),
      "\n轰一声一股巨大的雷电从天而降，打在"+victim->query("c_name")+"身上\n\n"
      );
      dam=35+random(45);
      victim->receive_special_damage("eletric",dam);
      report(this_object(),victim);
      return 1;
 }
