// �޺�ȭ
// the basic attack gonfu for monk...
// angel' 
inherit "/d/martial/attack/modify";
varargs int can_use(object me, object victim, object weapon)
{
	if( weapon ) return 0;
	return 1;
}

string *attack_msg = ({
	"%sʹ�������ﳯ����һ������%s",
	"%s����ǰ����˫������죬������׺����᡻ֱȡ%s",
	"%s��������һ�Σ�һ�ǡ����б��¡���%sһ��",
	"%s����һԾ�������Ǹ��¡���%s��������",
	"%s��ת����ʽ��ʹ������ݺ��ܡ���������ڡ�����%s",
	"%s���ֱ�ȭ�����ƴ�����Ҵ����֡�����%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
	return (25*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
	return (20*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
	return (9*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim,int type)
{
	if( !type ) return 0;
        return attack_msg[random(6)];
}
