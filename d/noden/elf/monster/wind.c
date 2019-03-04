#include "/d/noden/elf/layuter.h"
inherit MONSTER;

void create()
{
        ::create();
        set_level(7);
        set_name( "icers", "��ɪ˹" );
        set_short( "��ɪ˹");
        set("unit","λ");
        set_long( @LONG
��ɪ˹��һλ�����ݺ�ĵ�̼ң�������һ���д����˲���
����Ľ���������㳡�ϵ�ϣ��˹���񣬾��������������ʱ����
��ɵĿ���������������������봴���ĵͳ�����û�д��������
��������������������ȥ����������������ӣ���֪���Ƿ���԰�
��(help)����
LONG
        );
        set_perm_stat("str", 10);
        set_natural_weapon(10, 6, 10);
        set_natural_armor( 30, 14 );
        set ("gender", "male");
        set ("race", "elf");
        set_c_verbs(({"%s�����ĵ�̵���%s��ȥ","%s�����Ľ���%s��ȥ","%s������ȭͷ��%s����"}));
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�"}));
        wield_weapon(LWEAPON"guard_sword");
        equip_armor(LARMOR"wind_cloak");
        equip_armor(LARMOR"wind_boots");

        set("inquiry",([
           "help": 
                   "���İ��ĵ���(statue)�����ˣ�����������ļ��У�û�������Ҳ�֪��\n"
                   "�����������к����壬������ǰ��Ȫӿ�����ݵ����Ҳ�����ʧ���������Ƿ���԰�\n"
                   "���һ�����?\n",
           "statue": 
                   "���Ǹ�25����ʯ����Ʒ,����Ϊ��̫̫���������̵ĵ���,���ǵ���������\n"
                   "28�����գ����Ұѵ������������ǰʱ����ϲ�õر���������ת���裬����һ������ \n"
                   "��С��ʹ������ԶҲ��������һҹ���龰��ϣ��������һ���������һ����ĳ��͵(steal)\n"
                   "������\n ",
           "steal": 
                   "�������ʱ��������������һ�������ڱ������֣��������Ǹ������ұ���\n"
                   "������û���ҵ��κε���˿������������������ħ�Թ��Ѳ飬���Ǵ��Թ�������\n"
                   "�������������ǡ���!�����㵽�������\n"
      ]));
}

int accept_item(object player, object ob)
{
    if( !ob || !(ob->query("get_my_statue")) ) return 0;
	if( (string)ob->query("killer") != (string)player->query("name") ) {
		tell_object(player,
			"�ǳ���л��Ϊ�Ҵ������İ��ĵ��������д���֮���ˣ�Ը����Զ������\n"
			"��������пգ���˳������λ�һص����Ӣ��ͬ�������Һú�лл����!!\n"
			 );
		tell_room(environment(player), 
			"����˹�����İ��ĵ����ղ�������\n");
		ob->remove();
		return 1;
	}

    tell_object(player,
       "�ǳ���л��Ϊ�Ҵ������İ��ĵ��������д���֮���ˣ�Ը����Զ�����㡣\n"
       );
    if( (int)player->query_quest_level("icers") < 1 ) {
       player->finish_quest("icers",1);
       player->gain_experience(10000);
       tell_object(player,
          set_color("[����ɵ�̼Ұ�ɪ˹�����񣬵õ� 10000 �㾭��ֵ]\n","HIY",player));
       }
       ob->remove();
       tell_room(environment(player), 
           "����˹�����İ��ĵ����ղ�������\n");
	return 1;
}
