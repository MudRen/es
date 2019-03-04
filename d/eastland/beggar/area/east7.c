#include "../dony.h"

inherit ROOM;

int corner_search,have_exit;

void create()
{
	::create();
        set_short( "east7", "��·" );
	set_long(@C_LONG
������������һ������ʯ���̳ɵĴ�·��,��·���굽�����ƺ����Ǿ�ͷ����
·���ܴ�,Լ������һƥ����ʻ�Ŀ�ȡ���·�Գ���һЩ���ι�״��ֲ�� ,������
��������಻֪����С��,С���������е㵭������ζ, ��ζ��˵������ʹ������
����������������, ��ʱ�㷳�վ�ʧ,վ���������������ɾ�����Ķ�����һ���
ɫ�Ľ�����,ԭ�������� ( church )��
C_LONG
	);
        set_outside("noden");
	set( "exits", ([
	           "south":DBEGGAR"east5.c"
	]) );
        set( "item_func", ([
                 "corner" : "exam_corner"
        ]) );
        set("c_item_desc",([
                 "church":"һ���ɫ���Ͼ�����,����Խ�ȥ���� ( enter )��\n"
        ]) );
        corner_search = 0;
     reset();
}
void init()
{
      add_action("do_touch","touch");
      add_action("do_search","search" );
      add_action("to_enter","enter");
}

int to_enter(string str)
{
    if (!str) return 0;
    if (str=="church") {
        this_player()->move_player(DBEGGAR"church",({
            "%s������һ���Ͼɵ����á�\n",
            "%s���������˽���.\n"}),"");
        return 1;
    }
    else {
        write("�����������?\n");
        return 1;
    }
}

void exam_corner()
{
    if( !corner_search ) {
       write("������������ֵֹ�,�������ҿ� ( search ) �Ƿ���ʲ��?\n");
       return;
    }
    write("���߽���������Ѿ���Ū����,˵����ǽ�ᵹ��������\n");                                                    
}

int do_touch(string arg)
{
    if ( !corner_search )
            return notify_fail("��Ҫ��ʲ��?\n");
    
    if ( !arg || arg != "corner" )
        return notify_fail("��Ҫ��ʲ�ᶫ����\n");
    
    if ( !query("exits/north") ) {
       write(@C_LONG
������ִ������߱�Ū�ɵĽ��䣬ͻȻ��������һ��, ���ߵ�ǽ�ڻ������ص���
��,˲������ѹ�ı��ġ���ѽ!���������ò���,�����м���!!!
C_LONG
       );
    (DBEGGAR"east8")->set("exits/south",DBEGGAR"east7");
    if ( ( this_player() )->query_temp("jail_asked") ) {
       this_player()->receive_damage(15);
    } else { this_player()->receive_damage(100); }
    this_player()->set_temp("block_command",1);
    call_out("recover",15,this_player());
    tell_room(this_object(),this_player()->query("c_name")+
        "�����������ߵĽ���,ͻȻ��������һ�������ߵ�ǽ�����˰�����ѹ����..\n",
         this_player() );
    set("exits/north",DBEGGAR"east8");
      return 1;
    }
    write("��������ŵ�������Ͱѱ��ߵ�ǽ͵͵����������......\n");
    corner_search=0;
    delete("exits/north");
    (DBEGGAR"east8")->delete("exits/south");
    return 1;
}                                        

void recover(object toucher)
{
   toucher->set_temp("block_command",0);
   tell_object(toucher,"������ҳ�����������,�����Ǳ���\n");
}

int do_search(string arg)
{
   if( !arg || arg!= "corner" ) 
      return notify_fail("��Ҫ��ʲ����?\n");
   
   write( "�㵹��û���ҵ�ʲ��ֵǮ�Ķ���,�������߽������������Ū���ˡ�\n");
   corner_search=1;                        
   return 1;
}
void reset()
{
    (DBEGGAR"east8")->delete("exits/south");
    delete("exits/north");
    ::reset();
}
                                                                          