#include "../tsunami.h"

inherit ARMOR;

void create()
{
      set_name("Combat Armbands","����ս���ۻ�");
      add("id",({"arms","armbands"}) );
      set_short("����ս���ۻ�");
      set_long(@LONG
�����������Ҵ�ͳ��ս���ۻ��������������ҵļ��ƣ�����ʵ����ɣ���������ϲ��;
�����崩����ʱ����������֮��������������ʹ����ʮ��ǡ���ı���!
LONG
              );
      set("unit","��");
      set("type","arms");
      set("material","element");
      set("armor_class",4);
      set("defense_bonus",1);
      set("weight",20);
      set("value",({200,"silver"}) );
}              
                    
