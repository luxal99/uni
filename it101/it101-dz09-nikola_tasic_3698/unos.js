const attendanceTotal = document.querySelector("#attendanceTotal");
const testTotal = document.querySelector("#testTotal");
const homeworkTotal = document.querySelector("#homeworkTotal");

const attendance = document.querySelectorAll("input[name='attendance']");
const test = document.querySelectorAll("input[name='test']");
const homework = document.querySelectorAll("input[name='homework']");

const storage = {
	attendances: [],
	tests: [],
	homeworks: []
};

attendance.forEach(a =>
	a.addEventListener("change", () => {
		attendanceTotal.value = updateAttendance();
	})
);
test.forEach(t =>
	t.addEventListener("change", () => {
		testTotal.value = updateTest();
	})
);
test.forEach(t => {
	t.addEventListener("change", e => {
		if (2.5 < parseFloat(t.value)) t.value = 2.5;
		else if (0 > parseFloat(t.value)) t.value = 0;
		else if (isNaN(t.value)) t.value = 0;
	});
});
homework.forEach(h =>
	h.addEventListener("change", () => {
		homeworkTotal.value = updateHomework();
	})
);
homework.forEach(h => {
	h.addEventListener("change", e => {
		if (1.5 < parseFloat(h.value)) h.value = 1.5;
		else if (0 > parseFloat(h.value)) h.value = 0;
		else if (isNaN(h.value)) h.value = 0;
	});
});
function updateAttendance() {
	let total = 0;
	let result = [];
	attendance.forEach(a => {
		result.push(a.checked);
		if (a.checked) total++;
	});
	storage.attendances = result;
	localStorage.setItem("storage", JSON.stringify(storage));
	return total;
}

function updateTest() {
	let total = 0;
	let result = [];
	test.forEach(t => {
		if (!isNaN(t.value)) {
			result.push(t.value);
			total += parseFloat(t.value);
		}
	});
	storage.tests = result;
	localStorage.setItem("storage", JSON.stringify(storage));
	return total;
}

function updateHomework() {
	let total = 0;
	let result = [];
	homework.forEach(h => {
		if (!isNaN(h.value)) {
			result.push(h.value);
			total += parseFloat(h.value);
		}
	});
	storage.homeworks = result;
	localStorage.setItem("storage", JSON.stringify(storage));
	return total;
}
function init() {
	const storage = JSON.parse(localStorage.getItem("storage"));
	storage.attendances.forEach((v, i) => {
		attendance[i].checked = v;
	});
	storage.tests.forEach((v, i) => {
		test[i].value = v;
	});
	storage.homeworks.forEach((v, i) => {
		homework[i].value = v;
	});
	homeworkTotal.value = updateHomework();
	attendanceTotal.value = updateAttendance();
	testTotal.value = updateTest();
}
init();
