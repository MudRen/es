//butterfly's workroom

#include <mudlib.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        ::create() ;
        set("short", HIG "�ٻ�԰" NOR);
        set("long", 

"������"+BLINK HIM"����"NOR"�Ĺ����ҡ��㻹û���߽���԰�������
�Ѿ���������ˡ��ڻ�԰�ڷ��Ÿ��ָ�������ʢ������
������԰�����г���һ��֭Һïʢ����в������ֵĴ�
��(tree)�������°ڷ���һ��ʯ����ʯ�ʣ�ʯ���Ϸ���
һ��"+HIR"õ�廨"+NOR"(rose)��һ��"+HIW"�ؿ�"+NOR"(letter)��\n"
  NOR
  );

        set("light",1);
        set("virtual_server",1);
        set("no_cast",1);
        set("no_enhant",1);
 
        set("exits", ([
                "thi" : "/d/thief/hall/thief_guild",
                "mon": "/d/monk/guild/monk_guild",
                "kni": "/d/knight/fortress/knight_guild",
                "mag": "/d/mage/tower/mage_guild",
                "hea": "/d/healer/building/healer_guild",   
                "guild" : "/d/wiz/wiz_hall",
                "sch": "/d/scholar/scholar/scholar_guild",
        ]));
        set( "objects", ([
                "zhu": "/u/b/bfly/butterfly"
        ]) );
 
set("item_desc", ([
                "rose" : HIR "����һ�����˻�������ͨ�ĺ�õ�廨��\n" NOR,
                "letter" : HIG "͵�����˵��Ų�̫�ðɣ�\n" NOR,
                "tree" : CYN "��֪�����ܲ�����(climb)��ȥ��\n" NOR
        ]));

        reset();

}

void init()
{
        add_action( "climb_tree", "climb" );
        add_action( "break_rose", "break" );
        add_action("to_search", "search");
}
int climb_tree( string arg )
{
        if( !arg || arg!="tree" )
                return notify_fail( "��ʲ�᣿\n" );
                
        this_player()->move_player( "/u/b/bfly/tree", "SNEAK" );
 write( "���������ϡ�\n");

        tell_room( this_object(), 
                this_player()->query("c_name") + "�������ϡ�\n",
                this_player() );
        return 1;
}
int break_rose( string arg )
{
       object rose;
        rose = new(__DIR__"rose");
        if( !arg || arg!= "rose" )
                return notify_fail( "�����ʲô��\n" );
           rose->move(this_player());
  write(              
"��ӻ�԰��ժ��һ��"+HIR"��õ��"NOR"��\n");
       tell_room( this_object(), 
  this_player()->query("c_name") + "�ӻ�԰��ժ��һ��"+HIR"��õ��"NOR"��\n",
                this_player() );
        return 1;

}
int to_search(string arg)
{
    object o;

    write("ͻȻ�㷢���ڻ�����һ��"+HIY"�־�"NOR"��\n");
    o = new("/u/b/bfly/paper");
    o->move(this_object());
    return 1;
}
