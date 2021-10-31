var maps = [];
var markers = [];
function initMap() {
	var $maps = $('.map');
	$.each($maps, function(i, value) {
		var loc = { lat: parseFloat($(value).attr('lat')), lng: parseFloat($(value).attr('lng')) };

		var r_Id = $(value).attr('id');

		maps[r_Id] = new google.maps.Map(document.getElementById(r_Id), {
			zoom: 18,
			center: loc
		});

		markers[r_Id] = new google.maps.Marker({
			position: loc,
			map: maps[r_Id]
		});
	})
}
