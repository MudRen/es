#include "../tsunami.h"

inherit ARMOR;

void create()
{
      set_name("Combat Feet","����ս��ѥ");
      add("id",({"boots","feet"}) );
      set_short("����ս��ѥ");
      set_long(@C_LONG
�����������Ҵ�ͳ��ս��ѥ�������������ҵļ��ƣ�����ʵ����ɣ���������ϲ��; 
�����崩����ʱ����������֮��������������ʹ����ʮ��ǡ���ı���!
C_LONG
              );
      set("unit","˫");
      set("type","feet");
      set("material","element");
      set("armor_class",5);
      set("defense_bonus",2);
      set("weight",30);
      set("no_sale",1);
      set("value",({300,"silver"}) );
}              
                    
