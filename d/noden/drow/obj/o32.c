
#include <mudlib.h>
inherit OBJECT;

void create()
{
       set_name("evil dagger","а��ذ��");
       set_short("evil dagger","а��ذ��");
       add("id",({"dagger"}));
       set_long(@C_LONG
���ذ�׵��ձ��ϻ���һ���а���β�͵Ĺ��������
�ڣ���������������ɢ����һ����а�������а������
������ľ��飬�Ⲣ���ʺ���Ϊ��ս���õ�������
C_LONG );
      set("unit","��");
      set("weight",8);
      set("no_sale",1);
      set("no_clean",1);
      set("value",({410,"silver"}));
}
