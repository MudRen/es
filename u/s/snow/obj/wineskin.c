#include <mudlib.h>
inherit OBJECT;
void create()
{
        set_name("wineskin","ţƤ�ƴ�");
        set_short("�ƴ�");
        set( "weight", 10);
        set( "value", ({ 5, "silver" }));
        set("long", "һ��ţƤ��Ĵ�ƴ������װ�ðˡ������ľơ�\n");
        set("unit", "��");

}
void init()
{
        add_action("to_drink","drink");
}
int to_drink(string arg)
{
	object me;

        me = this_player();

        if( !arg || arg=="" || arg !="wine")
                tell_object(this_player(),
                "�����ʲô?\n"
                );
    else {
        tell_object(this_player(),
        "��һ��ͷ,���๾��غ��˼��ھ�.\n"
        );
        tell_room(this_object(),
                me->query("c_name")+"һ��ͷ,���๾��غ��˼��ھƣ�\n"
                , me);
	}
        return 1;
}

