#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "ghost of Bill", "�ȶ��Ĺ��" );
	add( "id", ({ "ghost", "bill" }) );
	set_short( "�ȶ��Ĺ��" );
	set_long(
		"�㿴��һ�����ݵ����ˣ��������������ƣ��������Ǹ���ꡣ\n"
	);
   set( "race", "undead" );
	set( "gender", "male" );
	set( "alignment", 200 );
	set_perm_stat( "str", 10 );
	set_perm_stat( "dex", 10 );
	set_skill( "dodge", 30 );
	set( "natural_armor_class", 20 );
	set( "natural_weapon_class1", 6 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 5 );
	set( "unbleeding",1);
	set( "tactic_func", "my_tactic" );
	set( "alt_corpse", "NONE" );
	set_c_verbs( ({"%s����ץ��%s"}) );
	set( "block_aim", ({ "vascular", "ganglion" }) );
	set( "chat_chance", 15 );
	set( "chat_output", ({
		"�ȶ�������: ��ħ(devil)��û������(name)�� ....\n",
		"�ȶ�������: �������� ....\n",
		"�ȶ�������: �������� .... ��\n",
		"�ȶ�������: ��˭ .... �� ....��\n",
		"�ȶ�������: �� .... �����ң�Կ��(key)�ڹ����(Harold)�������� ....\n"
	}) );
	set( "inquiry", ([
		"devil" :"�Ǹ�Ӥ���Ƕ�ħ��..... า���ԭ���ң������������" ,
		"name" :"�� .... �ҵ����ֽбȶ��������ǣ��Ҳ��Ƕ�ħ��" ,
		"key" : "Կ�� ... �ƽѵ�Կ�ס����𷥶�(Bravar)���� .... Ҳ������ .... " ,
		"harold" :"����������Ѿ����ˣ���Ҫɱ���Ǹ�Ӥ����ร�����...." ,
		"bravar" :"���𷥶�������λ�ʴȵ�ҽ�������Ǻ��� ...."
	]) );
}

int my_tactic()
{
	object *victim;
	int i;

	if( !(victim = query_attackers() ) || random(20)>5 ) return 0;
	tell_room( environment(this_object()), 
		"����Ӱ�ӱ��ģ����Ȼ���������������Ķ��ߴ���....\n" ,
		this_object() );
	for( i=0; i<sizeof(victim); i++ )
		victim[i]->receive_special_damage( "mental", 15 );
	return 1;
}

void die()
{
	tell_room( environment(this_object()), 
		query("c_cap_name") + "��Ӱ�ӻ���һ�ɰ��̣���ʧ�� ....\n",
		this_object() );
	::die(1);
}
