#include "../tsunami.h"

inherit ARMOR;

void create()
{
      set_name("Combat Headband","����ս��ͷ��");
      add("id",({"headband"}) );
      set_short("����ս��ͷ��");
      set_long(@LONG
���������������Դ�ͳ��ͷ�������ɺ����ı���˿��֯���ɣ�����ʵ����ɣ�����
��ϸ�����������ϲ��; ͨ����Ů�Ա�֯�͸��Լ���Ľ�����ԣ�����ʹ�����ܳ���
ƽ����
LONG
              );
      set("unit","��");
      set("type","head");
      set("material","wood");
      set("armor_class",6);
      set("defense_bonus",1);
      set("weight",20);
      set("value",({50,"gold"}) );
}              
                    
