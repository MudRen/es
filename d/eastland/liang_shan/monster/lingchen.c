#include "../takeda.h"
#include "/include/move.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "Ling Cheng", "��Ż�ҩʦ ����" );
	add("id",({"ling","cheng"}));
	set_short( "��Ż�ҩʦ ����" );
	set_long(
		"    ������ź����ף�����ʱԶ��Ĭ��˹��½ѧϰ������ҩ��ͬʱ��\n"
		"��һ��Ⱥ����������ר������û�й��˵����ͼ����ڵ����գ���ƾ��\n"
	        "����ר����Ҳ��������������\�͡�\n"
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
      "\n��Ż�ҩʦ���񷢳�һ���Ц�����ֶ���һ��ըҩ��һ�����춯�صľ���\n"
      "�ᣬ�ڳ����˶��ܵ����ص��˺�����ʱʧȥ����������\n",
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
//      "\n����е�: ��Ȼ�����գ���������һ��ը���ɣ�������.....\n"
//      "���������İ�һ��ը������"+killer->query("c_name")+"���������ߵ���...\n",
//      this_object());
//   if( (int)(ob1->move(killer)) != MOVE_OK )
//		ob1->move(environment(this_object()));  
//   ::die();   
//}
