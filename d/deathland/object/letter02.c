// Echo/item/letter01.c
#include "../echobomber.h"
inherit OBJECT;
void create()
{
set_name("scroll","��Ƥ����");
set_short("a scroll","��Ƥ����");
set("c_long",@LONG_D
һ��մ���������ľ���,����д���������������.\��\��\���������ȥ��(read)��.
LONG_D
);
set("no_sale",1);
set( "unit", "��");
set("weight", 5);
set("value", ({ 5, "silver" }));
}
void init()
{
add_action("read_letter","read");
}

int read_letter(string str)
{
    object ob1,room_1;
    if (!id(str)) return 0;
    else {
      ob1=environment(this_object());
      if (ob1!=this_player()) 
        return 0;
      else 
        {
          write(
          "������궼��˹����˿���, ���ײ�����Ƕ���ʯ, �������Ǹ�\n"
          "����ӡ�Ծõ�а����ٵ�ĹѨ. Ȼ��һ����ȴ��ס���ҵ�·, �ұ�\n"
          "��ȥѰ�����ŵ�Կ��..........\n"
          "��֪���������ػ��ǲ���, ��ʵ��û��ʲ�������а����ٰ¸���\n"
          "ĹѨ�л���ʲ����ֵ�����.\n"
          "                ------����̽�ռ�Ӣ�ɵ�\n"
          );
          return 1;      
        }
    }
}
