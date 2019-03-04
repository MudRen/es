#include "../legend.h"

inherit MONSTER;

void create()
{
        ::create();
        set_name( "old captain", "�ϴ���" );
        add("id",({"captain"}));      
        set_short( "�ϴ���");
        set("unit","λ");
        set_long(
@LONG
һλ�����ͷ���ϴ��������ں��ϲ��㼺������ʮ�����ʷ�ˣ�������Ϊ�������
�ˣ���Ǻ�������С�������ǵĹ����������ļ�Ǯ������������Ȼ�ֵ��µĴ��Ƚ�
�Ͼɣ��������ά�޵��ˣ�һֱû�����¡���Ȼ�������ֱ�Ӹ����⴬(rent boat
) ��
LONG
);
        set ("gender", "male");
        set ("race", "human");
        set("no_attack",1);
}

void init()
{
  add_action("rent_boat","rent");
}

int rent_boat(string arg)
{
  if (!arg||!(arg=="boat")) return notify_fail("�ϴ���˵������ү������ɶ��\n");

  if (this_player()->query_temp("mounting"))  
    return notify_fail(@C_LONG
�ϴ�����������Ӵ���������ѵ��������߻��������벻Ҫ��Ū��һ�����˼��
�ϴ���˵��͵�ͷ��ȥ�������㡣
C_LONG
      );
  tell_object(this_player(),@C_LONG
�ϴ���ϲ���ε�˵���������������治���ӽ��쿪ʼ�⴬һ����ѣ��ǺǺǡ�
��ָ���̰���һ��С��˵���ţ���˵���Һá���
�����ϴ����İ���֮�±�׾������С�����ӹ������Ĵ�������ʼ���԰Ѵ�������
�룬��Ȼ������Ĳ�Ū���������Ǵ�ֻ�ǲ�ͣ����ԭ�ش�ת��һʱ��æ���Ҳ�֪
������Ǻ�.........
  
C_LONG    
    );
  this_player()->set_temp("block_command",1);
  call_out("continue_rent",5);
  return 1;
}

int continue_rent()
{ 
  object ob1;   
  tell_object(this_player(),@C_LONG      
�ϴ�������һ�����Ц������������������ˡ�ֻ���ϴ�������һ�ɴ������ȵ�һ
��������ӵ̰��Ƶ����������ˡ�
�ϴ������㱳���������������·�ˣ�һֱ�������ͻص������ϣ���Ҫ���ˡ�
�ϴ������㱳���������������·�ˣ�һֱ�������ͻص������ϣ���Ҫ���ˡ�
�ϴ������㱳���������������·�ˣ�һֱ�������ͻص������ϣ���Ҫ���ˡ�
�ϴ������㱳���������������·�ˣ�һֱ�������ͻص������ϣ���Ҫ���ˡ�
�ϴ������㱳���������������·�ˣ�һֱ�������ͻص������ϣ���Ҫ���ˡ�
�ϴ������㱳���������������·�ˣ�һֱ�������ͻص������ϣ���Ҫ���ˡ�
�ϴ������㱳���������������·�ˣ�һֱ�������ͻص������ϣ���Ҫ���ˡ�
�ϴ������㱳���������������·�ˣ�һֱ�������ͻص������ϣ���Ҫ���ˡ�

C_LONG
    );
  tell_room(environment(this_object()),sprintf(
    "�㿴��ǰ��%s���ôӵ̰�����һ�Ҵ��������ϡ�\n",this_player()->query("c_name"))
    ,this_player());
  this_player()->move_player(LAKE"l_maze0","SNEAK");
  tell_room(environment(this_player()),sprintf(
    "%sҡ���������Ʊ�׾�ػ��˹�����\n",this_player()->query("c_name"))
    ,this_player());
  if (interactive(this_player())) {
    ob1 = new( LITEM"oar" );
    ob1->move(this_player());
  }
  this_player()->delete_temp("block_command");
  return 1;
}
