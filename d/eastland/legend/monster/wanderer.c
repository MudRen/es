#include <mudlib.h>

inherit MONSTER;

void create()
{
  ::create();
  set_level(15);
  set_name("wanderer","������");
  add( "id", ({ "wanderer" }) );
  set_short("������");
  set_long(@C_LONG
һ���¿������������˵��ˡ���˵�����������һ���Ժյļ��壬���ǣ���������
��һʱɱ�����𣬲���ʹ�����ļ�԰���ܴݲУ����Ǻ�����ʧɢ����ʹ�õ�ʱ���
��С������֪���룬������ȴ���������ʱ�ļ��䣬��Ϊ�����Ҹ��Ļ����С�
���ڣ�����֪���δ���ȥ���δ������ļң�����֪���ɹ��˽��죬��������ʲ����
������������������ϴ����ɼ�ս�Ҵ�����Ӱ�죬�����ƣ�����֪������������
ʥ�˲��ü�����֮����ϣ��������λ�߶��ܴ��б������˵��ػ����˽�Ȩ��������
����ɱ�˵ļ��ڡ�
C_LONG  
    );
  set( "race", "human" );
  set( "unit", "��" );
  set( "gender", "male");
  set_natural_weapon(30,18,33);
  set_natural_armor( 70, 18 );
  set( "max_hp", 400 );
  set( "hit_points", 400 );
  set_perm_stat( "int", 17 );
  set_perm_stat( "str", 20 );
  set_perm_stat( "dex", 22 );
  set_perm_stat( "pie", 18 );
  set("chat_chance",5);
  set("chat_output",({
     "������˵����......\n",
     "������˵�����ҵļ�....��..\n"
  }) );
  set( "att_chat_output", ({
     "�����߿�ɥ��������������������㻹�ڴ��ң�\n"
  }) );
}
