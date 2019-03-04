#include <mudlib.h>

inherit OBJECT;

int filled;

void create()
{
	set_name("cup", "����");
	add( "id", ({ "paper cup" }) );
	set_short( "ֽ��" );
	set("long","@@query_c_long");
	set( "quest_smith", 1 );
	set( "weight", 3 );
	filled = 0;
}

string query_c_long()
{
	if( filled )
		return "�������װ������ˮ������������ˮ��(drink)����(pour)����\n"
			"������ӿ��ܺܿ�������\n";
	else
		return  "���ֽ���ƺ���������װˮ������Ҫ����ֻ����һ����ˮ�ĵط�\n"
			"�� fill cup �ѱ���װ��ˮ��\n";
}

int query_filled() { return filled; }

void init()
{
	add_action( "fill_water", "fill" );
	add_action( "drink_water", "drink" );
	add_action( "pour_water", "pour" );
}

int fill_water(string arg)
{
	object env;

	if( !arg || arg!="cup" )
		return notify_fail("��ʲ��װˮ��\n");
	if( filled )
		return notify_fail("�������Ѿ�װ����ˮ�ˡ�\n");

	env = environment(this_object());
	if( living(env) ) env = environment(env);

	if( !env->query("water_source") )
		return notify_fail("����û��ˮ....��\n");

	filled = 1;
	write("��ѱ���װ����ˮ��\n");
	call_out("mess_up", 200);
	return 1;
}

int drink_water(string arg)
{

	if( !arg || arg!="cup" )
		return notify_fail("��ʲ�᣿\n");
	if( !filled )
		return notify_fail("�����ǿյġ�\n");
	filled = 0;
	write("���ֽ���е�ˮ�ȹ��ˡ�\n");
	return 1;
}

int pour_water(string arg)
{
	if( !arg || arg!="cup" )
		return notify_fail("����ʲ�᣿\n");
	if( !filled )
		return notify_fail("�����ǿյġ�\n");
	filled = 0;
	write("���ֽ���е�ˮ�����ˡ�\n");
	return 1;
}

void mess_up()
{
	object owner;

	owner = environment(this_object());
	if( living(owner) ) {
	tell_object(owner, "���ֽ�������ˣ����һ��ʪֽ�ţ������ֽ������ˡ�\n");
	}
	remove();
	return;
}
