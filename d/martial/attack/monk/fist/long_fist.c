// 少林寺武功「少林长拳」 
// modify by angel 
// 6/1 1994
inherit "/d/martial/attack/modify";
varargs int can_use(object me, object victim, object weapon)
{
        if( weapon ) return 0; // 徒手武功
        return 1;
}

// 各式战斗讯息
string *attack_msg = ({
        "%s使出『马步架打』右手向%s挥出",
        "%s使出一招『二龙分水』，砍向%s",
        "%s连续两招『老树盘根』『叶下藏花』，攻向%s",
        "%s左手护额，右手袭向%s，一招『顶心标拳』打出",
        "%s前弓後箭，使出一招『弓步顶肘』，打向%s",
        "%s一招『力劈华山』，砍向%s",
        "%s『舞花卧枕』、『□猫上树』连续使出，抓向%s",
        "%s几声轻啸，使出『天地相照』，击向%s",
        "%s使出『扫堂腿』，飞腿卷向%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
        return (20*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
        return (18*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
        return ((random(4)+3)*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim,int type)
{
        if( !type ) return 0;
        return attack_msg[random(9)];
}
