db.clubs.insertMany([
	{
		name: "FC Bayern Munich",
		nation: "Germany",
		league: "Bundesliga",
		goals: {
			scored: 37,
			conceded: 7,
		},
	},
	{
		name: "Manchester United",
		nation: "England",
		league: "Premier League",
		goals: {
			scored: 24,
			conceded: 17,
		},
	},
	{
		name: "Manchester City",
		nation: "England",
		league: "Premier League",
		goals: {
			scored: 34,
			conceded: 10,
		},
	},
	{
		name: "Liverpool",
		nation: "England",
		league: "Premier League",
		goals: {
			scored: 34,
			conceded: 15,
		},
	},
	{
		name: "Atletico Madrid",
		nation: "Spain",
		league: "LaLiga",
		goals: {
			scored: 30,
			conceded: 12,
		},
	},
	{
		name: "Real Madrid",
		nation: "Spain",
		league: "LaLiga",
		goals: {
			scored: 29,
			conceded: 11,
		},
	},
	{
		name: "Borrusia Dortmund",
		nation: "Germany",
		league: "Bundesliga",
		goals: {
			scored: 25,
			conceded: 18,
		},
	},
	{
		name: "FC Barcelona",
		nation: "Spain",
		league: "LaLiga",
		goals: {
			scored: 26,
			conceded: 20,
		},
	},
	{
		name: "Chelsea",
		nation: "England",
		league: "Premier League",
		goals: {
			scored: 33,
			conceded: 21,
		},
	},
	{
		name: "Juventus",
		nation: "Italy",
		league: "SerieA",
		goals: {
			scored: 26,
			conceded: 22,
		},
	},
]);

db.clubs.find().pretty();
db.clubs.find({}, { _id: 0 });

// average goals of the teams playing in different league
db.clubs.mapReduce(
	function () {
		emit(this.league, this.goals.scored);
	},
	function (key, values) {
		return Array.avg(values);
	},
	{
		out: "avg_goals",
	}
);

db.avg_goals.find().pretty();

// avergae goals of the teams playing in the league LaLiga
db.clubs.mapReduce(
	function () {
		emit(this.league, this.goals.scored);
	},
	function (key, values) {
		return Array.avg(values);
	},
	{
		query: { league: "LaLiga" },
		out: "avg_goals_laliga",
	}
);

db.avg_goals_laliga.find().pretty();
