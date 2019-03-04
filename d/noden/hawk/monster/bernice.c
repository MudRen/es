inherit MONSTER;
void create()
{
        ::create();
        set_level(3);
        set_name( "Bernice","柏妮丝" );
        add("id",({"bernice"}) );
        set_short( "柏妮丝" );
        set_long(@LONG
你看到一位亭亭玉立的少女，秀丽的面孔，细致的皮肤，不过脸上却挂著淡
淡的愁思，或许你可以帮帮她唷。
LONG
        );
        set( "inquiry", ([
                "help" : "@@help_me",
                "traito" : "@@ask_traito",
                "vito" : "@@ask_vito",
                "adolph" : "@@ask_adolph",
                ]) );
        set( "alignment", 100 );
        set( "gender","female" );
        set( "race","hawkman" );
        set( "time_to_heal", 10 );
        set_natural_armor( 20, 12 );
        set_natural_weapon( 25 , 13 , 17 );
        set( "wealth/silver", 300 );
}

int help_me()
{

        if ((int)this_player()->query_temp("find_ring") == 1 &&
           (present("blue ring",this_object())) )
        {
                tell_object(this_player(),@LONG
柏妮丝一看到你手中的戒指，脸色大变....
她叹了口气，说：唉....这件事说来话长。
....我想你应该知道鸟人族传统的比武大会吧。比武大会的优胜者可以获得
鸟人族领袖的地位，也因此我的爱人维多(Vito)就遭人陷害了。我一直想要
找到他最後的下落，并抚平他所受的伤害，洗刷他的耻辱，但却一直无法实
现。柏妮丝抬起头用满载著哀伤的眼神望著远方，轻轻的说：真希望能有人
肯帮助我....
你一股热血涌上心头，对著柏妮丝说：我会帮助你，让你不再悲伤....
LONG
                );
                this_player()->set_temp("bernice",1);
                this_player()->delete_temp("find_ring");
                return 1;
        }
        else if (this_player()->query_temp("smore_box") == 6)
        {
                tell_object(this_player(),@LONG
柏妮丝说：
        谢谢你，让维多能够瞑目～～～
你完成了『鸟人领袖之谜』的任务，得到 8000 点经验点的报酬。
LONG
                );
		this_player()->set_explore("noden#43");
		if ((int)this_player()->query_quest_level("vito's_wish") < 1) {
		this_player()->finish_quest("vito's_wish",1);
		this_player()->gain_experience(8000);
		}
        }

        else
        {
                tell_object(this_player(),@LONG
柏妮丝白了你一眼，说：这不甘你的事。
LONG
                );
                return 1;
        }
        return 1;
}


int ask_vito()
{
        if ((int)this_player()->query_temp("bernice") == 1)
        {
                tell_object(this_player(),@LONG
柏妮丝低著头说：
维多是我的未婚夫，也是我心目中的英雄。不知道从多久以前，他就一直是鸟
人族的领袖，领导著鸟人族的战士们对抗来犯的敌人，一次又一次的击退想要
染指天空之城的敌人。但是却在一年以前的比武大会中败给了他的弟弟，阿道
夫(Adolph)。不过奇怪的是，阿道夫本来没那麽厉害啊，真不知道为啥会在一
年之内武功突飞猛进，难道是因为偷吃禁药吗？
柏妮丝接著又说：
而且最近我总是梦到维多，他彷佛对我说著话，可是我却都听不懂，只隐隐约
约听到什麽雷多(Traito)害我....
LONG
                );
                this_player()->set_temp("traito",1);
                return 1;
        }
        else
        {
                tell_object(this_player(),"柏妮丝理都不理你。\n");
                return 1;
        }
        return 1;
}

int ask_adolph()
{
        if ((int)this_player()->query_temp("bernice") == 1)
        {
                tell_object(this_player(),@LONG
柏妮丝说：
阿道夫啊....是维多的弟弟，维多一向满照顾他的，不过他一向武艺都不强，
不知道为什麽会在去年一举击溃我的维多，而且看他跟本不像是在比武，跟本
是想把维多打死。而且在他当上鸟人族的领袖之後，不知道从哪里带回来一个
什麽锡卡拉教大祭司叫做裘拉根(Juraken) 的，两个人整天在一起，而且还要
我们鸟人族的战士们为他抵抗他的敌人。几个月前的一场大战害我们元气大伤
，大家对阿道夫都是敢怒而不敢言。
LONG
        );
                return 1;
        }
        else
        {
                tell_object(this_player(),"柏妮丝理都不理你。\n");
                return 1;
        }
}

int ask_traito()
{
        if ((int)this_player()->query_temp("traito") == 1)
        {
                tell_object(this_player(),@LONG
柏妮丝说：雷多是维多生前最信任的部下，随著维多出生入死好几次，自
从维多失踪，他就受到了阿道夫的赏识，地位越来越高。因为维多的关系，他
很照顾我，不过我最近觉得他好像怪怪的，不知道怎麽了。
LONG
                );
                return 1;
        }
        else
        {
                tell_object(this_player(),"柏妮丝理都不理你。\n");
                return 1;
        }
        return 1;
}

