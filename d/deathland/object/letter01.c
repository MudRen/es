// Echo/item/letter01.c
#include "../echobomber.h"
inherit OBJECT;
void create()
{
set_name("paper","�ƾɵ�ֽ��");
set_short("a paper","�ƾɵ�ֽ��");
set("c_long",@ScryBall
һ���Ѿ����Ƶ�ֽ��,����д���������������.\��\��\���������ȥ��(read)��.
ScryBall
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
    if (!str ||str!="paper") return 0;
    else {
      ob1=environment(this_object());
      if (ob1!=this_player()) 
        return 0;
      else 
        {
          write("�����ڰ����Թ����о�����ʮ����֮��, ����춷�����ͨ�����˴��\n"
                "��ȷ����,����ͬ���ذ�����ʦ��˹�˶�Ҳ��������,��ʹ�ø����ľ�\n"
                "ֹ��Ȼ�����׽������ ,�ҵľ�����ͬ�����������Ҿȳ�����ȴһһ\n"
                "ʧ����.��������İ��˰�����ĳ��ڷ�ס,�������������� .������\n"
                "���ľ�ͷ,�Ұ������˻�����˾õĸ����Թ����ܼ�¼����.ϣ��\n"
                "�ҵľ��˻���ܵ�֪,�ð������������Զ���ڿ־�֮��,���ð���.\n"
                "��������:�����Թ�֮��,��,��,��,��,��,��,��,��,���˵ĲƸ�����\n"
                "�������������֮����........��!��!��.\n"
                "\n\n                        _______����ħ��ʦ�ֶ�(Lindn)...\n"        
              );
          return 1;      
        }
    }
}
