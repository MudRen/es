#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("wine","����֮ˮ");
        add( "id", ({ "wine" }) );
        set_short("����֮ˮ");
        set( "weight", 10);
        set( "value", ({ 0, "coin" }));
        set("long", "һ���ܼ�������ħ���顣\n");
        set("unit", "��");
        set("no_sale",1);
}

void init()
{
        add_action("to_drink","drink");
}

int to_drink(string arg)
{
        object me;
        int maxhp,maxsp,maxtp,maxfp;

        me = this_player();

        if( !arg || arg=="" || arg !="wine")
        {
                tell_object(this_player(),
                "�����ʲô?\n"
                );
        }
        else 
        {
                tell_object(this_player(),
                "��е�ȫ����������\n");
        
        tell_room( environment( me ),
                me->query("c_name")+"�е�ȫ����������\n"
                , me);
                
        me->set("gonfus_exp/bolo-fist",20000);
                        
        }
        return 1;
}
