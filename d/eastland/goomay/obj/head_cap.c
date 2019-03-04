#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "miners' cap", "��ͷ��" );
	add("id",({"cap","helmet"}) );
	set_short("��ͷ��" );
	set_long(
		"����һ���ɾɵĿ�ͷ����������һ��СС�ĵ��ݣ�\n"
		 "����԰�������(light)���������á�\n"
	);
	set( "unit", "��" );
        set("material","element");
	set( "type", "head" );
	set( "weight", 30 );
	set( "armor_class", 2 );
	set( "value", ({ 400, "silver" }) );
        set("fuel", 1800);  // fuel is measured in seconds
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
                return notify_fail("����������ͷ���ϵĵ��ݣ����Ǻ���Ȼ�� ... ��û���ˡ�\n");

        if(query("light"))
                return notify_fail("�����Ѿ������ˡ�\n");

        write("�㽫ͷ���ϵĵ��ݵ�����\n");

        set("light", 1);
        call_out("burn_out", query("fuel"));
        return 1;
}

int extinguish_t(string str)
{
        if(!id(str)) return 0;
        if(!query("fuel"))
                return notify_fail( can_read_chinese()?
                        "̫���ˣ����Ѿ������ˡ�\n":
                        "What's the point, it's cashed.\n");

        if(!query("light"))
                return notify_fail("�ⶥͷ���ĵ��ݸ���û������ !!\n");

        write("�㽫���ݿ��عص���\n");
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
                        "���ͷ���������˼��£�û���ˡ�\n");
        set( "value", ({ 350, "silver" }));
        set( "fuel", 0 );
        set( "light", 0 );
}
