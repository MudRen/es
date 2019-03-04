// torch.c
// A torch - for seeing in the dark, roasting marshmallows, whatever you
// want, really.
// Written by Guile@TMI-2, 11-8-92.
// Thanks to Zeus@TMI-2 for a quickie fix, 1-22-93.

#include <mudlib.h>
inherit OBJECT;

void create()     
{
	set("short", "@@query_short");
	set("long", "@@query_long");
#include <compress_obj.h>
 	set_name( "torch", "���" );
	set("id", ({ "torch" }));
	set( "unit", "֦" );
	set("weight", 30);
	set("value", ({ 5, "silver" }));
	set("fuel", 900);  // fuel is measured in seconds
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
		return notify_fail( "�������Ѿ������ˡ�\n");

	if(query("light")) 
		return notify_fail( "�������Ѿ������ˡ�\n");

	write("�㽫��ѵ�����\n");
	set("light", 1);
	call_out("burn_out", query("fuel"));
	return 1;
}

int extinguish_t(string str)
{
	if(!id(str)) return 0;
	if(!query("fuel"))
		return notify_fail("̫���ˣ��������Ѿ������ˡ�\n");

	if(!query("light"))
		return notify_fail("�����ѻ�û�е��������Ϩ��\n");

	write("�㽫���Ϩ��\n");
	set("light", 0);
	set("fuel", remove_call_out("burn_out"));
	return 1;
}

void burn_out()
{
	object owner;

	owner = environment(this_object());
	if( living(owner) )
		tell_object( owner,"��Ļ�ѻ�����˼��£�Ϩ���ˣ������ְ����ӵ���\n");
	this_object()->remove();
/*
	set( "value", ({ 1, "silver" }));
	set( "fuel", 0 );
	set( "light", 0 );
	set( "useless", 1 );
*/
}

string query_short()
{
	if(query("fuel"))
		return "���" + (query("light") ? " (����)" : "");
	return "�չ�Ļ��";
}

string query_long()
{
	if(query("fuel"))
		return "���������������þߣ�\n" +
			(query("light") ? "�������ǵ����ģ������Ϩ��(unlight)����\n"
			: "����԰�����ȼ(light)ʹ�á�\n");
	return "�������Ѿ������ˡ�\n";
}
