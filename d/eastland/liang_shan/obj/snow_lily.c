#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
	set_name( "snow_lily", "��ɽѩ��" );
	add( "id", ({ "lily" }) );
	set_short( "��ɽѩ��" );
	set_long(@C_LONG
����һ������֮����������ı�����ɽѩ��������(eat)������ʹ����������
����\���ָ���
C_LONG
	);
	set( "no_sale", 1 );
	set( "unit","��");
	set( "weight", 1 );
	set( "value", ({ 450, "gold" }) );
}

int eat_food(string arg)
{
	if( !arg || ( arg !="lily" && arg !="snow_lily")  ) 
	return notify_fail("��ʲ��??"); 
	write( 
	"�����һ����ɽѩ�����ӵ�������һ������������ȫ��...\n" );
	tell_room( environment(this_player()), 
	this_player()->query("c_cap_name")+
	"����һ����ɽѩ�����ֻظ��������������\n" , this_player()
		);
		this_player()->receive_healing( 3+random(2) );
	        this_player()->set("force_points",(int)this_player()->query("max_fp"));
	remove();
	return 1;
}

