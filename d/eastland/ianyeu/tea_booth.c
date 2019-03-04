// /u/m/mad/room/tea_booth.c
#include "/d/eastland/ianyeu/mad.h"

inherit ROOM;

void create()
{
        ::create();
   set_short( "����" );
   set_long( @LONG
����վ��һ��С����֮��, �������������嵭�ҷ��Ĳ���,
����С�������ϵ�æ춴�������������Ϣ�Ŀ���֮��, �����˴�
���ⲻ��
LONG
        );
   set( "light", 1 );
   set( "objects", ([
           "waiter" : IANMOB"waiter",
           "father" : IANMOB"liang_father" ]) );
   set( "exits", ([
        "out" : "/d/eastland/10,13.east" ]) );
   reset();
}

void init()
{
   add_action( "sit_down", "sit" );
   add_action( "buy_item", "buy" );
}

int sit_down(string str)
{
   object waiter;

   if( !str || str != "down" )
   return notify_fail( "�㡺�ҡ���һ�������ڵ�!\n" );

   waiter = present( "waiter", this_object() );

   if( !waiter )
   return notify_fail( "�����˸���λ������, ��û�������к���!\n" );

   write( "�����ҵ�һ����λ������ʱ, ��С����æ��������˵��:\n"
          "����, ��Ҫ��Щʲ��? ���������ݴ�(tea)��(100����)?\n"
          "��Ѭ����(lamb)��(300����)?\n"
          "���ǿ�����Ҫ���Ա����ز����������(wine)��(600����)?\n");
   return 1;
}

int buy_item(string str)
{
        object waiter;
        waiter = present( "waiter", this_object() );

        if( !waiter )
        return notify_fail(
        "����: ��С�� ... ��С�� ... ���ǵ�С���ƺ�����!\n" );
        if (str == "wine")
        {
                if (this_player()->query_temp("get_wine") != 1)
                        return notify_fail(
                        "��С��˵�����ģ��������־��ǲ��������ม�\n" );
                tell_object(this_player(),@LONG
��С��˵���ۣ����Ĺ�Ȼ��ʶ���ġ�
����ת��ؾƽ�����ƿ����������������㡣
���ŵ���һ�����ص���ζ�����һ�ڰѸ����ȵ�ǬǬ������������Ȼ�úȡ�
�����׶�Ҫ�Ĵ�ž������������....��
LONG
                );
                this_player()->set_temp("get_wine",2);
                return 1;
        }
        return 1;
}

