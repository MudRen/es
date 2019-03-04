#include "takeda.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("iron lance","�������ǹ");
       add("id",({"iron-lance","lance",}) );
       set_short("�������ǹ");
	   set_long(
           "һ�����Ƶĳ�ǹ�����װ��ī��ɫ��ǹӧ��\n"
	);
	
	set( "unit", "��" );
 	set( "weapon_class", 35 );
        set("type","jousting");
	set( "min_damage", 25 );
	set( "max_damage", 30 );
	set( "weight", 180 );
	set( "nosecond",1);
	set( "value", ({ 610, "gold" }) );
    set("hit_func","lance_damage");
    set("special_damage",10);
    set("special_c_msg","�ϵ�ǹӧ����ס���˵����ߣ�ʹ���޷�������\n\n");
}

int lance_damage(object victim,int damage)
{
    object holder;
    int my_tac,vic_dex,dam,times;
    string c_msg,msg;
    
    if( !victim ) return 0;
      if (victim->query("stop_attack")) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	my_tac = (int)holder->query_skill("tactic");
        times =(my_tac)/35;
	if (times<=2) times =2;
	if (times>2) times =3; 
	vic_dex =(int)victim->query_stat("dex");
//         if( random(my_tac) < vic_dex*3  &&  (damage_count++)<=6)
// 6 round at least hit one and block 3 round, It seems too good
// Even delete damage_count, the probability is also too high, for a dex 20 mob, 40%success
         if( random(my_tac) < vic_dex*4)
		return 0;
	if( !(dam = (int)query("special_damage")) ) return 0;
	else {
		msg = (string)query("special_msg");
		c_msg = (string)query("special_c_msg");
		victim->receive_special_damage( dam );
		victim->set("last_attacker", holder );
		victim->set("stop_attack",times );
		if( !c_msg ) c_msg = msg;
//		if( !msg ) return 0;
// It has bug, It will let damage_count no set 0, so player can hit every round after 6 round
		tell_object( holder, 
			"\n���"+query("c_name")+c_msg+"\n");
		tell_room( environment(holder), 
			"\n" + holder->query("c_cap_name") + "��"+query("c_name")+c_msg+"\n",
			holder );
		damage_count=0;
		return dam;
     }
	
}	
