#include <mumar.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("The vault of kitchen","�ⷿ");
  set_long(@Long
Long
,@CLong
��������ʳ�⣬�ѷ�����ɽ���״��͸���ʳ�ƽʱ���Ӧ���Ǻ�Ǭ���ģ�����
��ȴ���������ȫ���������������ֲ�����ģ������״�(bag) Ҳ�ŵ�����Ť�˵أ�
���Ǳ��˷��䵹���һ�㡣
CLong
);
set("light",1);
set("c_item_desc",([ "bag":"@@to_bag" ]) );
set("exits",([ "west":MUMAR"kitchen" ]));
set("objects",([ "cookie":MOB"cook_master"]) );
reset();
}
 
string to_bag()
{
    return "�㿴����������֪������������......һ������ʮ������\n";
}
