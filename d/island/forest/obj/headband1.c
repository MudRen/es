#include "../tsunami.h"

inherit ARMOR;

void create()
{
      set_name("Police Headband","����ͷ��");
      add("id",({"headband","band"}) );
      set_short("����ͷ��");
      set_long(@LONG
����ħ��ı�����ִ������ʱ�ر���װ������ͷ��ӡ�б�ʤ��������������״
�������ӵĶ��䣬����ʩ�����ħ���������ܼ��緢�ּ��������
LONG
              );
      set("unit","��");
      set("type","head");
      set("material","cloth");
      set("armor_class",6);
      set("defense_bonus",1);
      set("weight",50);
      set("value",({300,"silver"}) );
}              
                    
