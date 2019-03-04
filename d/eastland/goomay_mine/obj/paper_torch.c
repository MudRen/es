

#include "../zeus.h"
inherit OBJECT;

void create()     
{
	set_name( "magic_paper", "ǧ���" );
	set("short", "@@query_short");
	set("long", "@@query_long");
	set("id", ({ "paper" }));
	set( "unit", "��" );
	set("weight", 5);
	set("fuel", 300);  // fuel is measured in seconds
}


void init()
{
	add_action("light_t", "blow");
	add_action("extinguish_t", "unlight");
}        
int light_t(string str)
{
	if(!id(str)) return 0;	

	if(query("light")) 
		return notify_fail( "����ǧ����Ѿ������ˡ�\n");

	write("�㴵��һ������ǧ���������ˡ�\n");
	set("light", 1);
	this_player()->set_temp("paper/light",1);
	call_out("burn_out", query("fuel"));
	return 1;
}

int extinguish_t(string str)
{
	if(!id(str)) return 0;	
	if(!query("fuel"))
		return notify_fail( "��������!����ǧ����Ѿ���Ϊ�ɻ��ˡ�\n");	
	if(!query("light"))
		return notify_fail("���ǧ���û�е��������Ϩ��\n");

	write("�㽫ҡһҡ�ֽ�ǧ���Ϩ��\n");
	set("light", 0);
	this_player()->set_temp("paper/light",0);
	set("fuel", remove_call_out("burn_out"));
	return 1;
}

void burn_out()
{       object ob; 
	object owner;
           ob = this_object();
	owner = environment(this_object());
	if( living(owner) ){
		tell_object( owner,"���ǧ��������˼��£����ɻ�Ϩ���ˡ�\n");
       ob->remove();
       this_player()->set_temp("paper/light",0);
	}
}

string query_short()
{
	if(query("fuel"))
		return "ǧ���" + (query("light") ? " (����)" : "");
}


string query_long()
{
	if(query("fuel"))
		return "ǧ�������Ŵ������������Դ��\n" +
			(query("light") ? "����ǧ����Ѿ������ˣ������Ϩ��(unlight)����\n"
			: "����Զ�����(blow)������ȼʹ�á�\n");
}
