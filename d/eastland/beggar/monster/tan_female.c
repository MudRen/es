#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "moon female", "阴婆婆" );
	add("id",({"moon","female"}) );
        set_short( "大别山碧云洞 阴婆婆" );
	set_long(@C_LONG
阴婆婆约莫五、六十岁年纪,身材牛马高大,白发如银,满脸皱纹和阳公公短小的身
材来比,相□成趣。 她自二十年前就与阳公公稳居在大别山碧云洞一直未涉世,最
近因丐帮的邀请特地赶来参加丐帮『祭祖大典』盛会。
C_LONG
	);
	set( "gender", "female" );
	set( "race", "human" );
	set( "alignment", 30 );
	set_natural_armor( 40 , 40 );
	set_natural_weapon( 50 , 25 , 33);
	set("max_hp",420);
	set("hit_points",420);
	set_perm_stat( "str", 26 );
	set_perm_stat( "dex",22 );
	set_perm_stat( "int",23 );
	set_skill( "parry",35 );
	set_skill( "dodge",60 );
	set( "wealth/silver",100);
	set( "special_defense", ([ "all": 35,"none":40 ]) );
	set( "aim_difficulty",(["critical":60,"vascular":40,"weakest":40]) );
	set("couple",1);
        set_c_verbs( ({ "%s使出『打咀巴』第一武, 欺向%s。",
                        "%s横身而来『打咀巴』第二招, 双手向%s打去。",
                        "%s大叫一声,『打咀巴』最强一式啪啪啪三个巴掌打向%s。"
                      }) ); 
        set( "chat_chance", 22 );
        set( "att_chat_output", ({
                "阴婆婆怒道:无知小贼,我阴婆婆岂是这麽好欺负的!! \n"
        }) );
                                         
        equip_armor(DARMOR"tan_ring");
        set( "tactic_func", "my_attack" );
} 

int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couple") ) return 1;
        return 0;
}

int my_attack()
{ 
    object victim, *couples;
    int i;
  
    victim = query_attacker();
    if( !victim ) return 0;

    couples = filter_array( all_inventory(environment(this_object())),
        "can_help", this_object() );
    for( i=0; i<sizeof(couples); i++ ) {
         tell_room( environment(this_object()), couples[i]->query("c_name")+
            "说道:想找我们过招,你们配吗?\n",couples[i]);
            couples[i]->kill_ob(victim);
    }
                                                      
    if  ( random(14)>2 )  return 0;
    else{
       tell_room( environment(this_object()),
           "阴婆婆手起落赏"+victim->query("c_name")+"一个老大括子!!\n",victim);
       tell_object( victim,"阴婆婆手起落赏你一个老大括子!\n");
       victim->receive_damage(12);
       return 1;
   }      
}


