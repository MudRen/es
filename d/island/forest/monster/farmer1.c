#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(5);
    set_name("Gardener","��԰��");
    set_short("��԰��");
    set_long(@LONG
    һ��ħ����Ϲ�����ȫ��Ƥ����ɹ�ú�����ģ������ڵ��������԰��
����Ҷ���Ӳݣ��������ʲ�ằ����ֲ����Ҫ�֣��������������Ϊ�����
�ģ���Ϊ���ռ�ϡ��ֲ������ʵ����԰���������Ĺ�����
LONG
            );
    set("unit","λ");
    set("race","daemon");
    set("gender","male");
    set("alignment",200);
    set_perm_stat("dex",7);
    set_perm_stat("str",5);
    set("max_hp",125);
    set("hit_points",125);
    set_skill("unarmed",30);
} 

int accept_item(object player,object obj)
{
    if( !obj || !(obj->query("luoko_seed"))) return 0;
      if( (string)obj->query("getter") != (string)player->query("name") ){
      write(@GET
��԰����Ц����Ŷ��С�ӣ�����������͵���İɣ�û�գ����Ͱ������������ˣ���
GET
           );
      return 1;
      }
    tell_room(environment(),
    "��԰���ɴ����۾����ò�������˫�ֽӹ����ӣ���æ�������������У�\n");
    obj->remove();
    call_out("grow_up",5,this_player() );
    return 1;
} 

int grow_up()
{
    if( present("luoky")) {
    tell_room(environment(),@ALONG

�˻ʹ���Ϊ԰���ֵ����ܲ�����Ѹ�ײ����ڶ����ٶȰ�����������.........
�찡���㶼��û��Ӧ�����գ�����

��԰��̾������С�ӣ�ֻ����ȥ��һ��������............
ALONG
             );
    return 1;
    }
    tell_room(environment(),@BLONG
��԰��˵����С���ӣ����������ˣ���ת��(report)����ϼ��������˵����û���ˣ�
����
BLONG
             ); 
    this_player()->set_temp("seed_ok",1);
    return 1;
}  
