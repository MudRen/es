#include <mumar.h>
inherit ROOM;
int cockroach = 1;
int fragment = 1;
 
void create()
{
        ::create();
  set_short("����ؽ̳�");
  set_long( @CLong
����ǽ̳������Ͻ��䣬��춳�������̦��ʹ�ó�ǽ������������������һ�㣬
���ݷ�����һ����ĽŲ�����̸�����ӳ�ǽ�ϴ�����ǽ������ضѻ���һЩ�������
��(box) ������������һЩȼ�չ��ĺۼ���
CLong
);
  set( "c_item_desc", ([
                "box" : @LONG_TEXT
��Щ�����϶�д��������Ʒ������С����š�֮������ۣ�������֪���������
����ˣ������紵�����ɹ����Щ�Ѿ���������ˡ�
LONG_TEXT
 ]) );
set_outside("eastland");
set("exits",([
               "north": MUMAR "square04",
               "east": MUMAR "square02" ]));
set( "search_desc", ([ "box" : "@@search_box","corner": "@@search_corner" ]) );
        reset();
}
 
string search_box()
{
        object obj;
 
        if( !cockroach || present("cockroach", this_object()) ) return
        "������е����Ӷ�����һ�飬����ʲ�ᶼ�Ҳ�����\n";
        obj = new( MOB"cockroach" );
        obj->move( this_object() );
        cockroach = 0;
        return
        "�㿪ʼ���䵹����Ҷ�������Ȼ�ܳ���һ����ɫë���׵Ķ���...�ţ���룡\n";
}
 
string search_corner()
{
        object obj;
 
        if( !fragment || present("fragment", this_object()) ) return
          "���ڽ��������˰��죬��������ʯͷ��û�п�����\n";
        obj = new( OBJS"fragment" );
        obj->move( this_object() );
        fragment = 0;
        return
         "���ڽ����￪ʼ���䵹����Ҷ���������ҵ���һƬ�龵�ӣ�\n";
}
