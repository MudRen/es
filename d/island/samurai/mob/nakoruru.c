#include "mercury.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "Nakoruru","娜考璐璐");
	add( "id", ({ "nakoruru" }) );
	set_short( "Nakoruru","娜考璐璐");
	set_long(@AAA
娜考璐璐是一个年仅十六.七岁的少女，有著一张清秀的脸孔与高贵的气质，还有一双
灵动眼睛，她一个待在这旅店好像很孤单的样子，或许你可以帮助她！！
AAA
 );
	set( "unit", "位" );
	set( "race", "human" );
	set( "gender", "female" );
	set( "forgetful",1);
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 20 );
        set_perm_stat( "dex", 30 );
        set_perm_stat( "kar", 30 );
        set_perm_stat( "pie", 25 );    
        set( "max_hp",750 );
        set( "hit_points",750 );
	set_natural_armor( 80,25 );
	set( "natural_weapon_class1", 25 );
	set( "natural_min_damage1", 20 );
	set( "natural_max_damage1", 40 ); 
        set( "special_defense",([ "all":15,"cold":30,"none":15 ])); 
        set( "stun_difficulty",17);  
	set( "alignment", 2000 );
	set_c_limbs( ({ "头部", "身体", "手腕", "咽喉" ,"前胸" }) );
        set_skill( "parry",100 );
        set_skill( "dagger",80 );
        set_skill( "dodge",100 );
        set_skill("tactic",100);
        set("tactic","melee");
        set( "wealth" , ([ "silver": 400 ]) );    
        wield_weapon(MOBJ"snow_dagger.c");
        equip_armor(MOBJ"snow_cloth.c");
        equip_armor(MOBJ"snow_cloak.c");
        equip_armor(MOBJ"snow_gloves.c");
        equip_armor(MOBJ"snow_amulet.c"); 
        set( "inquiry",([
             "help":"其实是因为我的男友加尔福特(Calford)最近都没有来看\n"
                    "我,而我的生日又要到了,他好像都不关心,所以我....",
             "calford":"加尔福特最近好像进了特殊部队受训练了,我也不想妨碍他受训\n"
                       "只希望你见到他时对他提一下我的名子,让他知道我在想他.\n"
                       ]));       
}
int accept_item(object player,object ob)
{
         if( !ob->query("nakoruru_statue") ) return 0;
         if( !player->query_temp("calford") ||
                !ob->query("statue_getter") ||
		(string)ob->query("statue_getter") != (string)player->query("name") ) {
            write("娜考璐璐笑笑的说：我很感谢你为了我而订做了我的雕像，但我的心上人是加尔福特..\n");
            command("give statue to "+(string)player->query("name") );
            return 1;
           }
          else{  write(@AAA
娜考璐璐高兴的说：原来他还没忘记我，还记得给我礼物，实在很谢谢你的帮忙！

娜考璐璐说完後偷偷在你的脸颊亲了一下．．．

AAA
);
             tell_room(environment(player),
   "娜考璐璐收下雕像後脸上露出非常幸福的表情\n"
                        );
             ob->remove();
             if( (int)player->query_quest_level("nako") <1  ){
                  player->finish_quest("nako",1);
                  write(@AAA
   
你完成了娜考璐璐任务得到经验值1500

AAA
                    );
                       player->gain_experience(1500);
                       return 1;
               }   
       }
}
