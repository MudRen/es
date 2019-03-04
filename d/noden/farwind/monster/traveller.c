#include <mudlib.h>

inherit MONSTER;

string *rumors = ({
	"��˵Ĭ��˹�۹��������Ҫ���ˣ���֪��������ǻ����һ������",
	"������뵽���������Ե���ɳ��ȥ�������Żʺ�Ŷɴ���",
	"��ɳ���ϱ���һ���ֹ�����ӣ���˵����һҹ֮�������ߡ��˸���....",
	"��ȥ����������ҵ����ڻ��㲻�����������ȷλ�á�",
	"���µ�ʱ����ķķ����������ͷ��������������ñ𿿽�����������....",
});

void create()
{
	object ob1, ob2, ob3;

	::create();
	set_level( 7 );
	set_name( "traveller", "��·�ÿ�" );
	set_short( "��·�ÿ�" );
	set_long(@C_LONG
����˿�������Ȼƣ�������������������ʵ�ļ����ֱۿ��Կ��ó�
����һ�����о�������мң��������ʱ�䣬������������һЩ���⸽
������һЩ����(rumors)��
C_LONG
	);
	set_perm_stat( "str", 10 );
	set_perm_stat( "kar", 10 );
	set_skill( "longblade", 70 );
	set_skill( "parry", 40 );

	set( "gender", "male" );
	set( "race", "human" );
	set( "wealth", ([ "gold" : 10 ]) );
	set( "inquiry", ([
		"rumors" : "@@ask_rumors" ]) );

	ob1 = new( "/d/noden/farwind/items/rapier" );
	ob1->move( this_object() );
	wield_weapon( ob1 );

	ob2 = new( "/d/noden/farwind/items/gloves" );
	ob2->move( this_object() );
	equip_armor( ob2 );

	ob3 = new( "/d/noden/farwind/items/buskin" );
	ob3->move( this_object() );
	equip_armor( ob3 );
}

string ask_rumors()
{
	int i;

	i = random(sizeof(rumors)/2) * 2;
	if( environment() )
		tell_room( environment(),
			"��·�ÿ�˵��: " + rumors[i+1] + "\n",
			this_object() );
}
