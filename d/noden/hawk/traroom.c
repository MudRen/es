//traroom.c
#include "hawk.h"
inherit ROOM;
int potion;
int mirror;
void create()
{
        ::create();
        set_short("Ư���ķ���");
        set_light(1);
        set_long( @LONG_DESCRIPTION
����һ��װ�ʮ�������ķ��ӣ�������������Ǯ�˼�ס�ĵط���ǽ�߰���һ
���������(closet)��װ���ϰٱ����飬�ѵ��ⷿ�ӵ�������һ������ʫ���
��������
LONG_DESCRIPTION
        );
        set( "exits", ([
                "out" : HAWK"room2-11",
                     ]) );
        set( "objects", ([
                "traito" : MOB"traito",
               "servant" : MOB"servant"])
                        );
        set("c_item_desc",([
                "closet":"@@to_closet"
                        ]) );
        reset();
}//end of creat

string to_closet()
{
        return "����һ���ܴ���������װ���ϰٱ����飬�����������������\n"
                +"Ӧ�û���һЩ�ռ䣬��֪������Щʲ�ᶫ����\n\n";
}

void init()
{
        add_action("to_search","search");
}

int to_search(string str)
{
        object obj,obj2;
        if (!str) return 0;
        if (str == "box")
        {
                if (this_player()->query_temp("smore_box") != 1)
                {
                        tell_object(this_player(),"���������ң���û�з����κζ�����\n");
                        return 1;
                }

                if ( present("traito",this_object()) )
                {
                        tell_object(this_player(),"�׶������һ�ۡ�\n");
                        return 1;
                }
                else
                {
                        tell_object(this_player(),"�����׶�����������ҵ�һƿ��ɫ��ҩˮ��\n");
                        obj = new(OBJ"potion");
                        obj->move(this_object());
                        potion = 0;
			this_player()->set_explore("noden#42");
                        this_player()->set_temp("smore_box",2);
                        return 1;
                }
                return 1;
        }
        if (str == "closet")
        {
                if (mirror == 0) return 0;
                tell_object(this_player(),"����������ҵ�һ�澵�ӡ�\n");
                obj2 = new(OBJ"mirror");
                obj2->move(this_object());
                mirror = 0;
                return 1;
        }
        return 1;
}


void reset()
{
        ::reset();
        potion = 1;
        mirror = 1;
}
