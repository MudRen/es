#include <mudlib.h>

inherit ARMOR;

void create()
{
      set_name("moon amulet","�·�");
      add("id",({"amulet"}) );
      set_short("�·�");
      set_long(@C_LONG
һ���幤��ϸ��ī��ɫ�������ڻ������������£����ױߵ�īɫ�������еø����
�����������Ƹ����ߴ��ŵ���Ů�������ش�����覡��·������Ѳ��ɿ�����������
������½һλ��ʦ��˵��������Ǿ����¹�ϴ���ħ��������춿���а����Ī���
Ч��������
C_LONG
      );
      set("unit","��");
      set("type","misc");
      set("material","cloth");
      set("defense_bonus",4);
      set("special_defense",(["evil":40]) );
      set("weight",1);
      set("value",({120,"gold"}) );
}