#include "../takeda.h"
#include "/include/move.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "Ling Cheng", "天才火药师 凌振" );
	add("id",({"ling","cheng"}));
	set_short( "天才火药师 凌振" );
	set_long(
		"    凌振外号轰天雷，少年时远赴默尔斯大陆学习火术爆药，同时解\n"
		"决一大群敌人是他的专长。虽没有过人的勇猛及出众的武艺，但凭著\n"
	        "他的专长，也立下了无数汗马功\劳。\n"
	);
	set( "race", "elf" );
	set( "gender", "male" );
	set( "alignment", 100 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "kar", 19 );
	set_skill( "unarmed", 80 );
	set_skill( "dodge", 70 );
	set( "wealth/gold", 20 );
	set( "special_defense", (["magic": 20 ]) );
	set("tactic_func","special_attack");
	set_natural_weapon( 8, 8, 8 );
	set_natural_armor( 20, 10 );
        equip_armor( TARMOR"vest");
        equip_armor( TARMOR"one_hood");
}
void announce( string c_msg )
{
	object *usr;
	int i;

	usr = users();
	for( i=0; i<sizeof(usr); i++ ) {
		if( !environment(usr[i]) ) continue;
		tell_object( usr[i], c_msg);
	}
}
int special_attack()
{
    object env,*inv,*victim;
    int i;
    env=environment(this_object());
    inv=all_inventory(env);
    if(random(10)<4) return 0;
    tell_room( environment( this_object() ), 
      "\n天才火药师凌振发出一阵狂笑，扬手丢出一捆炸药，一声惊天动地的巨响\n"
      "後，在场的人都受到严重的伤害，暂时失去攻击能力。\n",
      this_object()
    );
    i = sizeof(inv);
    while(i--) {
      if (inv[i]!=this_object()) 
        {
           inv[i]->receive_damage(random(10)+5);
           inv[i]->block_attack(random(2)+1);
           "/d/magic/magic"->report( this_object(), inv[i] );
        }
    }
    return 1;
}
//void die()
//{  
//   object ob1,killer;
//   ob1 = new(TOBJ"bomb");
//   killer = query("last_attacker");
//   if( !killer ) {
//     ::die();
//     return;
//   }
//   tell_room(environment(this_object()),
//      "\n凌振叫道: 果然好武艺，吃我最後一颗炸弹吧，哈哈哈.....\n"
//      "凌振无力的把一颗炸弹丢向"+killer->query("c_name")+"，而後力竭倒地...\n",
//      this_object());
//   if( (int)(ob1->move(killer)) != MOVE_OK )
//		ob1->move(environment(this_object()));  
//   ::die();   
//}
