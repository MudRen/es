/*
 * ԭ���ߣ�Mercury (1995.1)
 * �޸��ߣ�Ishige (1995.12)
 */
#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("Evil Sword","��������");
	add("id",({"sword"}) );
	set_short("Evil Sword","��������");
	set_long(@AAA
����һ�Ѵ�˵�еġ��������꡹�������Ϸ���һ�ɹ���Ĺ�â����˵
�˵��������ޱ�ǿ�������������������Ҫʹ�����������������Լ�
��������Ϊ������
AAA
);
	set("unit","��");
	set("weapon_class",45);
	set("type","longblade");
	set("min_damage",25);
	set("max_damage",47);
	set("weight",170);
	set("value",({130,"gold"}));
	set("hit_func","sword_damage");
	set("special_c_msg","��ʼ��ȡ�ֵ��ߵ����������� \n"
        "�������굶���Ϸ���һ��ǿ�ҵĹ�â��������˵����࣡����\n");
}

int sword_damage(object victim,int damage)
{
	object holder;
	int my_kar,dam;
	string c_msg,msg; 
	
	/*��춻���ĳֵ����Լ��� HP������нϸߵ� damage. */
	dam = 30;

	if( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
	
	my_kar = (int)holder->query_stat("kar");
	if( random(30) > my_kar/3 )
		return 0;
	else {
		c_msg = (string)query("special_c_msg");
		holder->receive_damage( 5+random(10) );
		victim->receive_special_damage( "none",dam );
		victim->set("last_attacker", holder );
		tell_object( holder,"\n���"+query("c_name")+c_msg+"\n");
		tell_room( environment(holder),
		holder->query("c_name") + "��"+query("c_name")+c_msg+"\n",
		holder );
		return dam;
	}
}