
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(18);
        set_name( "Master Fan", "�ų�������������" );
        add ("id",({ "fan","master"}));
        set_short( "�ų�������������");
        set("unit","λ");
        set_long(
@C_LONG
    �������������µġ���ӥ�������죬Ҳ���ǵ��������������һλ
���������������£���֪�����˶����永��ն�˶��ټ����˵��һ����
�ʵ���ǰ�����֪��Ϊʲ��������������֣���Ӧ�ò���żȻ�� !!
C_LONG
);
        set ("gender", "male");
        set ("race", "human");
	set("alignment",1000);
        set_natural_armor( 90, 40 );
        set_natural_weapon( 10, 10, 23 );
        set_perm_stat( "str", 30 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "dex", 30 );
        set_skill( "shortblade", 100 );
        set_skill( "parry", 100 );
        set_skill( "block", 100 );
        set( "hit_points", 900 );
        set( "max_hp", 900 );
        set( "special_defense", ([ "all": 40 ]) );
        set( "wealth/gold", 100 );
        wield_weapon( Obj"icey_sword" );
        equip_armor( Obj"flame_shield" );
	
        set( "inquiry", ([
                "wine" : 
@WINE
���� !! ����һ���������ӵľ��������컹�ص���һ�ԣ�
û�뵽Ҳûʲ����˵ģ������ǵ�̫��¥Ҳ���࣬������Ϊʧ�����ѵ�������
��û�кþ��� ...��
WINE
]));

}
int accept_item(object me,object item)
{
     if ((string) item->query("name") !="old wine" ) return 1;
     tell_object(me,
@MISSION
�������Ŀ��ϾƵķ��࣬һ������Ѿ�͸�˳�����������Ĵָ����Ц�������þ� !!����
�����������������̸��˵�ز������ !! �ȵ�������������̸����е����� ...
ԭ�����ϻ���ܱ�����������ı������ͼ�ڻ��Ϲ���������֮ʱ��ɱ�ִ�ɱ����
�����������ǰ����졣�������Ѿ�����һ���������ּ����������ˣ�����һֱû
����Ϣ���������Լ�������̽��
MISSION
	);
                item->remove();
	return 1 ;
}
