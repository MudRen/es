inherit MONSTER;

void create()
{
        ::create();
        set_level(5);
        set_name( "hawkman older", "鸟人族老人" );
        add("id",({"older","hawkman"}) );
        set_short( "鸟人族老者" );
        set_long(@LONG
老态龙锺的鸟人族老人，正在遥想著以往英勇的往事。你若是想知道一些鸟人族的
过去(history) ，或许可以问问这为慈祥的老人。
LONG
        );
        set( "gender", "male" );
        set( "inquiry", ([
                "flesheater":"@@ask_flesh",
                   "history":"@@ask_history",
                       "war":"@@ask_war"
                        ]) );
        set( "race", "hawkman" );
        set( "alignment", 300 );
        set( "time_to_heal", 15 );
        set_natural_armor( 13, 2 );
        set_natural_weapon( 10 , 12 , 5 );
        set_perm_stat( "kar", 13 );
        set( "wealth/silver", 50 );
}

int ask_war()
{
        tell_object(this_player(),@LONG
老人用很害怕的语气说：大概在几个月前吧，塔姆姆酋长撒巴吐卡(Sa-ba'tuka)
带了好几百人的部队攻打我们，在天空之城坚固的防御工事下，我们抵挡住塔姆姆族
的攻击。想不到原本以为没事了的我们，却在晚上被撒巴吐卡用邪魔法攻击，完全摧
毁了我们的武力。所幸裘拉根呼唤出许多地狱中的魔物协助我们，尤其是太古魔兽--
肉食兽....
    老人似乎陷入了极度的恐慌，不说话了。
LONG
                );
        return 1;
}

int ask_flesh()
{
        tell_object(this_player(),@LONG
老人大喊：喔....不要再提起那可怕的怪物了。

你觉得这或许是所有鸟人族人心中最大的恐惧吧!!
LONG
                );
        return 1;
}

int ask_history()
{
        tell_object(this_player(),@LONG
老人说：鸟人族一向生活在高山中，与外界无所争，传说中的天空之城，是我们
鸟人族的圣地，也是我们聚居的地方。而每年所举行的比武大会，推选出鸟人族的领
袖，带领著我们抵抗意图染指天空之城的异族。不过因为我们一向和外界没啥来往，
所以也不常会有战争的发生。....
    不过自从阿道夫当上我们的领袖之後，就有点不一样了，他的好朋友裘拉根和塔
姆姆族是世仇，这一年来为了追杀裘拉根，以经发动了数次战争(war) ，鸟人族的战
士也是死伤惨重。为了一个素不相识的外族人....唉....真是不值得啊。
LONG
                );
        return 1;
}
