#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "white dog Lucky", "С�׹� ����" );
	add("id",({"dog","lucky"}));
	set_short( "С�׹� ����" );
	set_long(@C_LONG
һֻȫ���׺�����ë��С������ԭ�ǻ���ʦ��Ů�����ģ�ǰ������Ϊ׷����ĳ��
��ȴ���ҵ�������������أ�����һϢ��������ͣ�������˿ڣ��������죬����
���ˡ�����������ӣ��������԰���װ������ȥ��   
C_LONG
        );
        set("unit","ֻ");
        set("no_attack",1);
        set("lucky",1);
        set("max_hp",100000);
        set("hit_points",1);
        set("chat_chance",10);
        set("chat_output",({
           "�ء��ء��ء���\n"
       }) );
}
