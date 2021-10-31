<%@ page contentType="text/html; charset=utf-8"%>
<%@ page import="java.sql.*" %>
<html>
<head>
	<title>Result</title>
	<link rel="stylesheet" href="./resources/css/bootstrap.min.css" />
  	<script src="./resources/js/map2.js"></script>
  	<script src="./resources/js/jquery-3.6.0.min.js"></script>
</head>

<body>

<div style="width:90%; margin:auto">
<h1>Result</h1>
<table class="table table-hover table-bordered">
 <thead>
   <tr bgcolor = "skyblue" align="center">
      <th>이미지</th>
      <th>지도</th>
      <th>상세위치</th>
      <th>삭제</th>
   </tr>
 </thead>
 <tbody>
 
 	<%@ include file="dbconn.jsp" %>
 	<%
 		PreparedStatement pstmt = null;
 		ResultSet rs = null;
 		String sql = "select * from result";
 		pstmt = conn.prepareStatement(sql);
 		rs = pstmt.executeQuery();
 		while (rs.next()) {
 	%>
 
   <tr align="center">
      <td style="width:30%"><img src="./resources/images/<%=rs.getString("r_pic")%>" style="height:300"></td>
      <td style="width:30%">
  <div class="map" id="<%=rs.getString("r_id")%>" lat="<%=rs.getString("lat")%>" lng="<%=rs.getString("lng")%>" style="width:300; height:300;"></div>
      </td>
      <td style="width:20%"><%= rs.getString("lat")%>, <%=rs.getString("lng")%></td>
      <td style="width:20%"><a href="./deleteResult.jsp?r_id=<%= rs.getString("r_id")%>" class="btn btn-danger" role="button">삭제</a></td>
   </tr>
   <%
 		}
 	if (rs != null)
 		rs.close();
 	if (pstmt != null)
 		pstmt.close();
 	if (conn != null)
 		conn.close();
   %>
   <script async defer src="https://maps.googleapis.com/maps/api/js?key=AIzaSyDrCFzEbGco1z0IZPsGfpw2BtpRbhI03JA&callback=initMap&region=kr"></script>
 </tbody> 
</table>

  
<footer class = "container">
<p>&copy; 2021 Capstone</p>
</footer>
</body>
</html>