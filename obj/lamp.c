
#include <mudlib.h>
inherit OBJECT;

void create()     
{
	set_name( "lamp", "�͵�" );
	set("short", "@@query_short");
	set("long", "@@query_long");
	set( "unit", "յ" );
	set("weight", 40);
	set("value", ({ 20, "silver" }));
	set("fuel", 1500);  // fuel is measured in seconds
}


void init()
{
	add_action("light_t", "light");
	add_action("light_t", "ignite");
	add_action("extinguish_t", "extinguish");
	add_action("extinguish_t", "unlight");
}

int light_t(string str)
{
	if(!id(str)) return 0;
	if(!query("fuel"))
		return notify_fail("��յ�͵Ƶĵ����Ѿ������ˡ�\n");

	if(query("light")) 
		return notify_fail("��յ�͵��Ѿ������ˡ�\n");

	write( "�㽫�͵Ƶ�����\n");
	set("light", 1);
	call_out("burn_out", query("fuel"));
	return 1;
}

int extinguish_t(string str)
{
	if(!id(str)) return 0;
	if(!query("fuel"))
		return notify_fail("̫���ˣ������Ѿ������ˡ�\n");

	if(!query("light"))
		return notify_fail("��յ�͵ƻ�û�е��������Ϩ��\n");

	write("�㽫�͵�Ϩ��\n");
	set("light", 0);
	set("fuel", remove_call_out("burn_out"));
	return 1;
}

void burn_out()
{
	object owner;

	owner = environment(this_object());
	if( living(owner) )
		tell_object( owner,
			"����͵ư���������Ϩ���ˡ�\n");

	set ("value", ({ 1, "silver" }));
	set ("fuel", 0);
	set ("light", 0);
}
/*
string query_short()
{
	if(query("fuel"))
		return "a lamp" + (query("light") ? " (lit)" : "");
	return "a lmap";
}
*/

string query_short()
{
	if(query("fuel"))
		return "�͵�" + (query("light") ? " (����)" : "");
	return "�͵�";
}

/*
string query_long()
{
	if(query("fuel"))
		return "It is a light source.\n" +
			(query("light") ? "It is lit.\n" : "It is not lit.\n");
	return "It used to be a light source.\n";
}
*/

string query_long()
{
	if(query("fuel"))
		return "�͵���һ�ֳ����������þߣ�\n" +
			(query("light") ? "��յ�͵��ǵ����ģ������Ϩ��(unlight)����\n"
			: "����԰�����ȼ(light)ʹ�á�\n");
	return "��յ�͵Ƶĵ����Ѿ��ù��ˡ�\n";
}
