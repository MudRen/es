// File: /d/eastland/haiwei/temple1.c

#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("����");
        set_long( @C_LONG_DESCRIPTION
����һ����ۣ����Ϲ�����������ۣ���Ȼ��̫�󣬵���ʮ��Ǭ�������
��һ����¯���ֽ��м���\���������������˼���۵���ͽ���٣��Ҳ���һ������
��(box)��
C_LONG_DESCRIPTION
        );
    set("objects",([
        "toaist":"/d/eastland/haiwei/monster/toaist"]));
        set( "light", 1 );
        set( "item_desc", ([ 
                "box" : "����һ����ٺ��\n"]) );
        set( "exits", ([ 
                "west" : "/d/eastland/haiwei/temple_square" ]) );
        reset();
}


void init()
{
        add_action( "do_put", "put" );
}

int do_put(string arg)
{
        string type;
        int num;
        object ob1;

        if( !arg || arg=="" || sscanf( arg, "%d %s",num, type)!=2 )
                return notify_fail( can_read_chinese()?
                        "��ʲ�᣿\n": "Put whom what?\n" );
        if( !this_player()->debit(type, num) ) return notify_fail( can_read_chinese()?
                "��û�������Ǯ��\n": "You don't have that many coins.\n" );
    if (present("toaist",this_object())){
       this_player()->credit(type,-num);
       write(can_read_chinese()?
          "�ϵ�˵����Ȼ���ѱ����ĳ��⣬�͸���һ���������ɡ�\n":
          "\n");
       ob1=new("/d/eastland/haiwei/obj/paper");
       ob1->move(this_object());
       return 0; 
      }  
}       
