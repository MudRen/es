#include "../tsunami.h"

inherit ARMOR;

void create()
{
      set_name("Combat Cloth","����ս��װ");
      add("id",({"cloth"}) );
      set_short("����ս��װ");
      set_long(@C_LONG
�����������Ҵ�ͳ��ս��װ�������Ȼ��ʮ�����ۣ�����ʵ����ɣ����������ϲ��;
�����崩����ʱ����������֮��������������ʹ����ʮ��ǡ���ı���!
C_LONG
              );
      set("unit","��");
      set("type","body");
      set("material","element");
      set("armor_class",25);
      set("defense_bonus",2);
      set("weight",130);
      set("value",({1500,"silver"}) );
}