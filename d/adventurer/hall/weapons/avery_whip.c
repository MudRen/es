#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name("tears of avery","������֮��");
        add( "id",({ "avery", "whip" }) );
        set_short( "������֮��" );
        set_long(@CLONG
    ���Ǵ�ð�ռҰ�����ר�õı��ӣ���˵���ǰ������ڱ����������������С����
ð��ʱ���õ�ս��Ʒ����ʱ��֪��������ʲ���£�ʹ������������ǿ��ı�������Ϊ
��������֮�᡹��
CLONG
);
        set( "unit", "��");
        set( "weapon_class", 40 );
        set( "type", "whip" );
        set( "min_damage", 25 );
        set( "max_damage", 34 );
        set( "weight", 120 );
        set( "value", ({ 800, "silver" }) );
        set_c_verbs( ({
          "%s��Ϊһ����Ӱ��Ѹ�����׵ľ���%s",
          "%s�����趯����Ӱ��Ϊǧ�٣�ֱ����%s",
         }) );
        set( "extra_skills",(["anatomlogy":10,"parry":10]));
}
